#include "stdafx.h"
#include "Dragonite.h"

Dragonite::Dragonite()
{
	//이름
	_name = L"망나뇽";
	_num = 15;


	//스탯(개체값)
	_pokemonValue.hp = 91;
	_pokemonValue.attack = 134;
	_pokemonValue.defense = 95;
	_pokemonValue.sattack = 100;
	_pokemonValue.sdefense = 100;
	_pokemonValue.speed = 80;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_DRAGON;
	_type[1] = POKEMON_TYPE_FLYING;

	_jump = true;
}

Dragonite::~Dragonite()
{
}

HRESULT Dragonite::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("dragonite_idle",
		L"img/pokemon/15. dragonite/idle.png", 124, 770, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("dragonite_move",
		L"img/pokemon/15. dragonite/move.png", 248, 770, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("dragonite_attack",
		L"img/pokemon/15. dragonite/attack.png", 198, 726, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("dragonite_sattack",
		L"img/pokemon/15. dragonite/sattack.png", 66, 682, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("dragonite_hurt",
		L"img/pokemon/15. dragonite/hurt.png", 66, 836, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("dragonite_sleep",
		L"img/pokemon/15. dragonite/sleep.png", 108, 56, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("dragonite_default",
		L"img/pokemon/15. dragonite/default.png", 62, 770, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("dragonite_portrait",
		L"img/pokemon/15. dragonite/portrait.png", 40, 40);

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
	_skill.push_back(3);
	_skill.push_back(5);
	_skill.push_back(10);
	_skill.push_back(14);
	_skill.push_back(15);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(20);
	_skill.push_back(22);

	return S_OK;
}
