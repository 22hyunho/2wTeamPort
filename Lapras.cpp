#include "stdafx.h"
#include "Lapras.h"

Lapras::Lapras()
{
	//이름
	_name = L"라프라스";
	_num = 28;


	//스탯(개체값)
	_pokemonValue.hp = 130;
	_pokemonValue.attack = 85;
	_pokemonValue.defense = 80;
	_pokemonValue.sattack = 85;
	_pokemonValue.sdefense = 95;
	_pokemonValue.speed = 60;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_WATER;
	_type[1] = POKEMON_TYPE_ICE;

	_jump = false;
}

Lapras::~Lapras()
{
}

HRESULT Lapras::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("lapras_idle",
		L"img/pokemon/28. lapras/idle.png", 98, 1078, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("lapras_move",
		L"img/pokemon/28. lapras/move.png", 392, 1078, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("lapras_attack",
		L"img/pokemon/28. lapras/attack.png", 294, 1078, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("lapras_sattack",
		L"img/pokemon/28. lapras/sattack.png", 196, 1078, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("lapras_hurt",
		L"img/pokemon/28. lapras/hurt.png", 98, 1078, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("lapras_sleep",
		L"img/pokemon/28. lapras/sleep.png", 144, 60, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("lapras_default",
		L"img/pokemon/28. lapras/default.png", 98, 1078, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("lapras_portrait",
		L"img/pokemon/28. lapras/portrait.png", 40, 40);

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
	_skill.push_back(8);
	_skill.push_back(15);
	_skill.push_back(20);
	_skill.push_back(24);
	_skill.push_back(25);

	return S_OK;
}
