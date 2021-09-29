#include "stdafx.h"
#include "Golbat.h"

Golbat::Golbat()
{
	//이름
	_name = L"골벳";
	_num = 17;


	//스탯(개체값)
	_pokemonValue.hp = 75;
	_pokemonValue.attack = 80;
	_pokemonValue.defense = 70;
	_pokemonValue.sattack = 65;
	_pokemonValue.sdefense = 75;
	_pokemonValue.speed = 90;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_POISON;
	_type[1] = POKEMON_TYPE_FLYING;

	_jump = true;
}

Golbat::~Golbat()
{
}

HRESULT Golbat::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("golbat_idle",
		L"img/pokemon/17. golbat/idle.png", 186, 682, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("golbat_move_attack",
		L"img/pokemon/17. golbat/move_attack.png", 248, 682, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_MOVE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("golbat_sattack_default",
		L"img/pokemon/17. golbat/sattack_default.png", 62, 682, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("golbat_hurt",
		L"img/pokemon/17. golbat/hurt.png", 46, 484, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("golbat_sleep",
		L"img/pokemon/17. golbat/sleep.png", 132, 34, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = _stateImage[POKEMON_STATE_SATTACK];


	//초상화
	_portrait = IMAGEMANAGER->addDImage("golbat_portrait",
		L"img/pokemon/17. golbat/portrait.png", 40, 40);

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
	_skill.push_back(2);
	_skill.push_back(7);
	_skill.push_back(8);
	_skill.push_back(9);
	_skill.push_back(10);
	_skill.push_back(17);
	_skill.push_back(22);


	return S_OK;
}
