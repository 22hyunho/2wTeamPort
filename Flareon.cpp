#include "stdafx.h"
#include "Flareon.h"

Flareon::Flareon()
{
	//이름
	_name = L"부스터";
	_num = 23;


	//스탯(개체값)
	_pokemonValue.hp = 65;
	_pokemonValue.attack = 130;
	_pokemonValue.defense = 60;
	_pokemonValue.sattack = 95;
	_pokemonValue.sdefense = 110;
	_pokemonValue.speed = 65;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_FIRE;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Flareon::~Flareon()
{
}

HRESULT Flareon::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("flareon_idle",
		L"img/pokemon/23. flareon/idle.png", 174, 638, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("flareon_move_attack",
		L"img/pokemon/23. flareon/move_attack.png", 232, 638, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_MOVE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("flareon_sattack",
		L"img/pokemon/23. flareon/sattack.png", 116, 638, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("flareon_hurt",
		L"img/pokemon/23. flareon/hurt.png", 66, 726, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("flareon_sleep",
		L"img/pokemon/23. flareon/sleep.png", 104, 42, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("flareon_default",
		L"img/pokemon/23. flareon/default.png", 58, 638, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("flareon_portrait",
		L"img/pokemon/23. flareon/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(포켓몬마다 조정해줘야함)
	_count[POKEMON_STATE_IDLE] = 0.8 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 1.0;
	_count[POKEMON_STATE_SLEEP] = 0.5;
	_count[POKEMON_STATE_DEFAULT] = 0.5;

	//상태별 미세조정
	_tuningX = 0;
	_tuningY = 0;

	//attack 2차 함수
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);

	//스킬 목록
	_skill.push_back(1);
	_skill.push_back(7);
	_skill.push_back(9);
	_skill.push_back(10);
	_skill.push_back(18);

	return S_OK;
}
