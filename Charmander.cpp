#include "stdafx.h"
#include "Charmander.h"

Charmander::Charmander()
{
	//이름
	_name = L"파이리";
	_num = 1;


	//스탯(개체값)
	_pokemonValue.hp = 39;
	_pokemonValue.attack = 52;
	_pokemonValue.defense = 43;
	_pokemonValue.sattack = 60;
	_pokemonValue.sdefense = 50;
	_pokemonValue.speed = 65;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_FIRE;
	_type[1] = END_POKEMON_TYPE;

	_jump = true;
}

Charmander::~Charmander()
{
}

HRESULT Charmander::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("charmander_idle",
		L"img/pokemon/1. charmander/idle.png", 144, 528, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("charmander_move",
		L"img/pokemon/1. charmander/move.png", 192, 528, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("charmander_attack",
		L"img/pokemon/1. charmander/attack.png", 144, 528, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("charmander_sattack",
		L"img/pokemon/1. charmander/sattack.png", 46, 550, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("charmander_hurt",
		L"img/pokemon/1. charmander/hurt.png", 48, 528, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("charmander_sleep",
		L"img/pokemon/1. charmander/sleep.png", 96, 48, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("charmander_default",
		L"img/pokemon/1. charmander/default.png", 48, 528, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("charmander_portrait",
		L"img/pokemon/1. charmander/portrait.png", 40, 40);

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
	_count[POKEMON_STATE_DEFAULT] = 0.3;

	//상태별 미세조정
	_tuningX = 0;
	_tuningY = 0;

	//attack 2차 함수
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);

	//스킬 목록
	_skill.push_back(1);
	_skill.push_back(9);
	_skill.push_back(10);
	_skill.push_back(14);
	_skill.push_back(18);

	return S_OK;
}