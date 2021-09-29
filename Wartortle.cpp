#include "stdafx.h"
#include "Wartortle.h"

Wartortle::Wartortle()
{
	//이름
	_name = L"어니부기";
	_num = 11;


	//스탯(개체값)
	_pokemonValue.hp = 59;
	_pokemonValue.attack = 63;
	_pokemonValue.defense = 80;
	_pokemonValue.sattack = 65;
	_pokemonValue.sdefense = 80;
	_pokemonValue.speed = 58;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_WATER;
	_type[1] = END_POKEMON_TYPE;

	_jump = true;
}

Wartortle::~Wartortle()
{
}

HRESULT Wartortle::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("wartortle_idle_default",
		L"img/pokemon/11. wartortle/idle_default.png", 48, 550, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("wartortle_move",
		L"img/pokemon/11. wartortle/move.png", 192, 550, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("wartortle_attack",
		L"img/pokemon/11. wartortle/attack.png", 144, 550, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("wartortle_sattack",
		L"img/pokemon/11. wartortle/sattack.png", 224, 594, 4, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("wartortle_hurt",
		L"img/pokemon/11. wartortle/hurt.png", 48, 528, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("wartortle_sleep",
		L"img/pokemon/11. wartortle/sleep.png", 92, 46, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = _stateImage[POKEMON_STATE_IDLE];

	//초상화
	_portrait = IMAGEMANAGER->addDImage("wartortle_portrait",
		L"img/pokemon/11. wartortle/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(포켓몬마다 조정해줘야함)
	_count[POKEMON_STATE_IDLE] = 0.6 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
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
	_skill.push_back(5);
	_skill.push_back(10);
	_skill.push_back(21);
	_skill.push_back(24);

	return S_OK;
}
