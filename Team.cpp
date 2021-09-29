#include "stdafx.h"
#include "Team.h"

HRESULT Team::init(int pokemonNum, int level)
{
	Player::init(pokemonNum, level);

	//플레이어 타입
	_playerType = PLAYER_TYPE_TEAM;
	_playerState = POKEMON_STATE_DEFAULT;
	//패턴
	//_pattern[PLAYER_PATTERN_PATHFINDER] = new PatternPathFinder;
	//_pattern[PLAYER_PATTERN_ONATTACK] = new PatternOnAttack;
	//changePattern(PLAYER_PATTERN_PATHFINDER);


	//기술
	_selectedSkill = nullptr;
	_default = SKILLDEX->makeSkill(0);
	_default->init(this);

	setSkill(3);

	return S_OK;
}

int Team::input()
{
	_direct = RND->getFromIntTo(RIGHT, DOWN + 1);
	_destX = _x;
	_destY = _y;

	_playerState = POKEMON_STATE_MOVE;
	if (_direct == RIGHT)
		_destX++;
	else if (_direct == LEFT)
		_destX--;
	else if (_direct == UP)
		_destY--;
	else if (_direct == DOWN)
		_destY++;
	else
		_playerState = POKEMON_STATE_ATTACK;


	return _playerState;
}
