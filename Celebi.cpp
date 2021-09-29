#include "stdafx.h"
#include "Celebi.h"

Celebi::Celebi()
{
	//이름
	_name = L"세레비";
	_num = 37;


	//스탯(개체값)
	_pokemonValue.hp = 100;
	_pokemonValue.attack = 100;
	_pokemonValue.defense = 100;
	_pokemonValue.sattack = 100;
	_pokemonValue.sdefense = 100;
	_pokemonValue.speed = 100;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_PSYCHIC;
	_type[1] = POKEMON_TYPE_GRASS;

	_jump = false;
}

Celebi::~Celebi()
{
}

HRESULT Celebi::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("celebi_idle_sattack",
		L"img/pokemon/37. celebi/idle_sattack.png", 84, 594, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("celebi_move",
		L"img/pokemon/37. celebi/move.png", 168, 594, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("celebi_attack",
		L"img/pokemon/37. celebi/attack.png", 126, 594, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("celebi_hurt",
		L"img/pokemon/37. celebi/hurt.png", 54, 726, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("celebi_sleep",
		L"img/pokemon/37. celebi/sleep.png", 72, 50, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("celebi_default",
		L"img/pokemon/37. celebi/default.png", 42, 594, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("celebi_portrait",
		L"img/pokemon/37. celebi/portrait.png", 40, 40);

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
	_skill.push_back(2);
	_skill.push_back(6);
	_skill.push_back(10);
	_skill.push_back(11);
	_skill.push_back(12);
	_skill.push_back(13);
	_skill.push_back(17);
	_skill.push_back(20);
	_skill.push_back(21);
	_skill.push_back(22);

	return S_OK;
}
