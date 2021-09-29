#include "stdafx.h"
#include "PatternOnAttack.h"

HRESULT PatternOnAttack::init(Player * player)
{
	Pattern::init(player);

	if (!_pathFinder) {
		_pathFinder = new PathFinder;
		_pathFinder->init();
	}
	_pathFinder->resetPathList();

	return S_OK;
}

void PatternOnAttack::release()
{
}

void PatternOnAttack::update()
{
	//if(collisionmanager->room player) true면 실시간으로 찾고
	//else false면 경로 한번 찾고
	_pathFinder->setTiles(_player, (*TURNMANAGER->getAllPlayer())[0]);
	_pathFinder->update();
	_pathList = _pathFinder->getPathList();

	//목적지 설정
	_player->setDestX(_pathList[0]->getIdX());
	_player->setDestY(_pathList[0]->getIdY());
	_player->setDirect();

	//충돌 검사
	//주변 8타일에 있으면 공격
	if (COLLISIONMANAGER->detectionWith8Tiles(_player, (*TURNMANAGER->getAllPlayer())[0])) {
		int num = RND->getInt(4);
		Skill** skill = _player->getSkill();

		if (skill[num])
			_player->useSkill(num);
		else
			_player->useSkill(-1);
	}
	else {
		//없으면 찾아감
		if (COLLISIONMANAGER->playerWithPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			//방향에 따라서 검사
			detour();
		}
	}
}

void PatternOnAttack::render()
{
}

void PatternOnAttack::detour()
{
	int direct = _player->getDirect();
	switch (direct) {
	case RIGHT:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() + 1);
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case LEFT:
		_player->setDestX(_player->getX() - 1);
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	case UP:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY() - 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case DOWN:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY() + 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	case RIGHT | UP:
		_player->setDestX(_player->getX());
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() + 1);
			_player->setDestY(_player->getY());
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case LEFT | UP:
		_player->setDestX(_player->getX());
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY());
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	case RIGHT | DOWN:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY());
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX());
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case LEFT | DOWN:
		_player->setDestX(_player->getX() - 1);
		_player->setDestY(_player->getY());
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX());
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	default:
		break;
	}
}
