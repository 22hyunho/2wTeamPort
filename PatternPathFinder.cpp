#include "stdafx.h"
#include "PatternPathFinder.h"

HRESULT PatternPathFinder::init(Player * player)
{
	Pattern::init(player);

	if (!_pathFinder) {
		_pathFinder = new PathFinder;
		_pathFinder->init();
	}
	_pathFinder->resetPathList();

	return S_OK;
}

void PatternPathFinder::release()
{
}

void PatternPathFinder::update()
{
	//저장된 경로가 없으면 새로 길 찾기
	if (_pathList.size() <= 0) {
		_pathFinder->setTiles(_player);
		_pathFinder->update();
		_pathList = _pathFinder->getPathList();
	}

	_player->setDestX(_pathList[0]->getIdX());
	_player->setDestY(_pathList[0]->getIdY());
	_player->setDirect();

	//충돌 검사
	if (COLLISIONMANAGER->playerWithPlayer(_player)) {
		//목적지 설정
		_pathList.erase(_pathList.begin());
		_player->setPlayerState(POKEMON_STATE_MOVE);
	}
	else
		detour();
}

void PatternPathFinder::render()
{

}

void PatternPathFinder::detour()
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
				_pathFinder->resetPathList();
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
				_pathFinder->resetPathList();
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
				_pathFinder->resetPathList();
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
				_pathFinder->resetPathList();
			}
		}
		break;

	case RIGHT | UP:
		_player->setDestX(_player->getX());
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//.erase(_pathList.begin());
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
				_pathFinder->resetPathList();
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
				_pathFinder->resetPathList();
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
				_pathFinder->resetPathList();
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
				_pathFinder->resetPathList();
			}
		}
		break;

	default:
		break;
	}
}
