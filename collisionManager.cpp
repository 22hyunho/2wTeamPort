#include "stdafx.h"
#include "collisionManager.h"
#include "Scene.h"
#include "ItemManager.h"
#include "Player.h"


HRESULT collisionManager::init(Scene * scene)
{
	_scene = scene;

	_allTile = TILEMANAGER->getvTile();
	_allItem = _scene->getItemManager()->getVItem();
	_allPlayer = TURNMANAGER->getAllPlayer();

	return S_OK;
}

void collisionManager::release()
{
}

bool collisionManager::collisionInputPlayer(Player * player)		// User, Enemy 안에 함수 부름
{
	if (!playerWithTile(player)) return false;
	if (!playerWithPlayer(player)) return false;

	return true;
	//플레이어 x, y기준으로 방향에 따라 1타일만 검사
	//이동가능하면 true, 아니면 false 반환
}

bool collisionManager::playerWithTile(Player * player)
{
	int tileWidth = TILEMANAGER->getWidth();	//가로 타일 갯수

	int directCount = 0;
	int playerIndex = player->getY() * tileWidth + player->getX();
	int index[11] = { 0, };

	//8방향 인덱스
	index[RIGHT] = playerIndex + 1;
	index[LEFT] = playerIndex - 1;
	index[UP] = playerIndex - tileWidth;
	index[DOWN] = playerIndex + tileWidth;
	index[UP | RIGHT] = index[UP] + 1;
	index[UP | LEFT] = index[UP] - 1;
	index[DOWN | RIGHT] = index[DOWN] + 1;
	index[DOWN | LEFT] = index[DOWN] - 1;


	int direct = player->getDirect();			//방향마다 다음타일 하나만 검사
	//좌우
	if ((direct & RIGHT) == RIGHT) {
		if ((*_allTile)[index[RIGHT]]->terrain <= TR_BLOCK)		return false;
		directCount |= RIGHT;
	}
	else if ((direct & LEFT) == LEFT) {
		if ((*_allTile)[index[LEFT]]->terrain <= TR_BLOCK)		return false;
		directCount |= LEFT;
	}

	//상하
	if ((direct & UP) == UP) {
		if ((*_allTile)[index[UP]]->terrain <= TR_BLOCK)		return false;
		directCount |= UP;
	}
	else if ((direct & DOWN) == DOWN) {
		if ((*_allTile)[index[DOWN]]->terrain <= TR_BLOCK)		return false;
		directCount |= DOWN;
	}

	//대각
	if ((*_allTile)[index[directCount]]->terrain <= TR_BLOCK)	return false;


	return true;
}

bool collisionManager::playerWithPlayer(Player * player)
{
	int tileWidth = TILEMANAGER->getWidth();	//가로 타일 갯수

	int playerIndex = player->getY() * tileWidth + player->getX();
	int index[11] = { 0, };

	//8방향 인덱스
	index[RIGHT] = playerIndex + 1;
	index[LEFT] = playerIndex - 1;
	index[UP] = playerIndex - tileWidth;
	index[DOWN] = playerIndex + tileWidth;
	index[UP | RIGHT] = index[UP] + 1;
	index[UP | LEFT] = index[UP] - 1;
	index[DOWN | RIGHT] = index[DOWN] + 1;
	index[DOWN | LEFT] = index[DOWN] - 1;

	vector<Player*>::iterator playerIter;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if ((*playerIter) == player) continue;

		int destX, destY;
		if ((*playerIter)->getPlayerState() == POKEMON_STATE_MOVE) {
			destX = (*playerIter)->getDestX();
			destY = (*playerIter)->getDestY();
		}
		else {
			destX = (*playerIter)->getX();
			destY = (*playerIter)->getY();
		}

		int direct = player->getDirect();			//방향마다 다음타일 하나만 검사
		//좌우
		if (direct == RIGHT) {
			if ((*_allTile)[index[RIGHT]]->x == destX &&
				(*_allTile)[index[RIGHT]]->y == destY)			return false;
		}
		else if (direct == LEFT) {
			if ((*_allTile)[index[LEFT]]->x == destX &&
				(*_allTile)[index[LEFT]]->y == destY)			return false;
		}

		//상하
		else if (direct == UP) {
			if ((*_allTile)[index[UP]]->x == destX &&
				(*_allTile)[index[UP]]->y == destY)				return false;
		}
		else if (direct == DOWN) {
			if ((*_allTile)[index[DOWN]]->x == destX &&
				(*_allTile)[index[DOWN]]->y == destY)			return false;
		}

		//대각
		else if (direct == (UP | RIGHT)) {
			if ((*_allTile)[index[UP | RIGHT]]->x == destX &&
				(*_allTile)[index[UP | RIGHT]]->y == destY)		return false;
		}
		else if (direct == (UP | LEFT)) {
			if ((*_allTile)[index[UP | LEFT]]->x == destX &&
				(*_allTile)[index[UP | LEFT]]->y == destY)		return false;
		}

		else if (direct == (DOWN | RIGHT)) {
			if ((*_allTile)[index[DOWN | RIGHT]]->x == destX &&
				(*_allTile)[index[DOWN | RIGHT]]->y == destY)	return false;
		}
		else if (direct == (DOWN | LEFT)) {
			if ((*_allTile)[index[DOWN | LEFT]]->x == destX &&
				(*_allTile)[index[DOWN | LEFT]]->y == destY)	return false;
		}
	}

	return true;
}



void collisionManager::collisionEndTurnPlayer(Player* player)
{
	playerWithItem(player);
	playerWithObject(player);
	if (player->getPlayerType() == PLAYER_TYPE_ENEMY)
		collisionDetection(player);
}

void collisionManager::playerWithItem(Player* player)
{
	for (int i = 0; i < _allItem->size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &player->getBody(), &(*_allItem)[i]->getBody()))
		{
			DIALOGMANAGER->addItemLog(player, (*_allItem)[i]);
			if (player->getPlayerType() <= PLAYER_TYPE_TEAM)
			{
				SOUNDMANAGER->play("PickUp");
				INVENTORYMANAGER->addItem((*_allItem)[i]);
			}
			_scene->getItemManager()->removeItem(i);
		}
	}
	
}
void collisionManager::playerWithObject(Player * player)
{
	if (player->getPlayerType() != PLAYER_TYPE_USER) return;

	int x = player->getX();
	int y = player->getY();

	int index = y * TILEMANAGER->getWidth() + x;

	RECT temp;
	if (IntersectRect(&temp, &player->getBody(), &(*_allTile)[index]->rc))
	{
		if ((*_allTile)[index]->obj == OBJ_STAIR)
		{
			//계단과 충돌시 로딩씬으로 넘어가기
			TURNMANAGER->setPause(true);
			CAMERAMANAGER->setFade(FADEOUT);
		}
	}
}

void collisionManager::collisionDetection(Player * player)
{
	Player* user = (*TURNMANAGER->getAllPlayer())[0];

	//주변 8타일 검사
	if (!detectionWith8Tiles(player, user)) {
		//방 충돌 검사
		detectionWithRoom(player, user);
	}
}

bool collisionManager::detectionWithRoom(Player * startPlayer, Player * destPlayer)
{
	vector<RECT>* rooms = TILEMANAGER->getvRoom();
	vector<RECT>::iterator room = rooms->begin();

	RECT tmp;
	for (; room != rooms->end(); ++room) {
		//현재 방 안에 있으면
		RECT rc = RectMake(room->left * TILEWIDTH, room->top * TILEHEIGHT,
			(room->right - room->left) * TILEWIDTH, (room->bottom - room->top) * TILEHEIGHT);
		if (IntersectRect(&tmp, &startPlayer->getBody(), &rc)) {
			//해당 방 안에 플레이어가 있는지 검사
			if (IntersectRect(&tmp, &destPlayer->getBody(), &rc)) {
				startPlayer->changePattern(PLAYER_PATTERN_ONATTACK);
				return true;
			}
		}
	}

	//방안이 아니거나 방에 유저가 없거나
	return false;
}

bool collisionManager::detectionWith8Tiles(Player * startPlayer, Player * destPlayer)
{
	int tileWidth = TILEMANAGER->getWidth();	//가로 타일 갯수

	//8방향 인덱스
	int initX = startPlayer->getX() - 1;
	int endX = startPlayer->getX() + 1;
	int initY = startPlayer->getY() - 1;
	int endY = startPlayer->getY() + 1;

	int destX = destPlayer->getDestX();
	int destY = destPlayer->getDestY();

	for (int i = initY; i <= endY; i++) {
		for (int j = initX; j <= endX; j++) {
			if (i == startPlayer->getY() && j == startPlayer->getX()) continue;

			if ((*_allTile)[i * tileWidth + j]->x == destX &&
				(*_allTile)[i * tileWidth + j]->y == destY) {
				startPlayer->setDestX(destX);
				startPlayer->setDestY(destY);
				startPlayer->changePattern(PLAYER_PATTERN_ONATTACK);

				return true;
			}
		}
	}

	return false;
}

void collisionManager::effectWithEnemy(Effect * effect)
{
	RECT temp;
	vector<Player*>::iterator playerIter;
	bool fail = true;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if (IntersectRect(&temp, &(*playerIter)->getBody(), &effect->getBody()))
		{
			//결정력이 양수(팀) -> 에너미
			//결정력이 음수(적) -> 팀(유저 포함)
			//두 경우에만 충돌로 처리
			if ((effect->getDamage() > 0 && (*playerIter)->getPlayerType() == PLAYER_TYPE_ENEMY) ||
				(effect->getDamage() < 0 && (*playerIter)->getPlayerType() <= PLAYER_TYPE_TEAM)) {

				SOUNDMANAGER->play("hitDamage");
				(*playerIter)->getPokemon()->changeState(POKEMON_STATE_HURT);
				(*playerIter)->hitDamage(BATTLEMANAGER->damageCalculation((*playerIter), effect));

				//HP가 0보다 낮아지면 -> 바로 지우면 ㅈ됨
				if ((*playerIter)->getCurrentHP() <= 0)
					(*playerIter)->getPokemon()->setDeath(true);

				TURNMANAGER->setPause(true);
				fail = false;
				break;
			}
		}
	}

	if (fail)
		DIALOGMANAGER->failSkillLog();
}