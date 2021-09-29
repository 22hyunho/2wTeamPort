#include "stdafx.h"
#include "Enemy.h"
#include "PatternPathFinder.h"
#include "PatternOnAttack.h"

HRESULT Enemy::init(int pokemonNum, int level)
{
	Player::init(pokemonNum, level);

	//�÷��̾� Ÿ��
	_playerType = PLAYER_TYPE_ENEMY;
	_playerState = END_POKEMON_STATE;
	//����
	_pattern[PLAYER_PATTERN_PATHFINDER] = new PatternPathFinder;
	_pattern[PLAYER_PATTERN_ONATTACK] = new PatternOnAttack;
	changePattern(PLAYER_PATTERN_PATHFINDER);


	//���
	_selectedSkill = nullptr;
	_default = SKILLDEX->makeSkill(0);
	_default->init(this);

	setSkill(3);

	return S_OK;
}

int Enemy::input()
{
	_pattern[_currentPattern]->update();

	return _playerState;
}