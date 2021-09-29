#include "stdafx.h"
#include "Jolteon.h"

Jolteon::Jolteon()
{
	//이름
	_name = L"쥬피썬더";
	_num = 22;


	//스탯(개체값)
	_pokemonValue.hp = 65;
	_pokemonValue.attack = 65;
	_pokemonValue.defense = 60;
	_pokemonValue.sattack = 110;
	_pokemonValue.sdefense = 95;
	_pokemonValue.speed = 130;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_ELECTRIC;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Jolteon::~Jolteon()
{
}

HRESULT Jolteon::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("jolteon_idle",
		L"img/pokemon/22. jolteon/idle.png", 62, 660, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("jolteon_move",
		L"img/pokemon/22. jolteon/move.png", 248, 660, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("jolteon_attack",
		L"img/pokemon/22. jolteon/attack.png", 248, 660, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("jolteon_sattack_hurt",
		L"img/pokemon/22. jolteon/sattack_hurt.png", 66, 814, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = _stateImage[POKEMON_STATE_SATTACK];

	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("jolteon_sleep",
		L"img/pokemon/22. jolteon/sleep.png", 104, 46, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("jolteon_default",
		L"img/pokemon/22. jolteon/default.png", 62, 660, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("jolteon_portrait",
		L"img/pokemon/22. jolteon/portrait.png", 40, 40);

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
	_skill.push_back(3);
	_skill.push_back(7);
	_skill.push_back(10);
	_skill.push_back(17);
	_skill.push_back(18);

	return S_OK;
}
