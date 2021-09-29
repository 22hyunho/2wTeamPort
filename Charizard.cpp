#include "stdafx.h"
#include "Charizard.h"

Charizard::Charizard()
{
	//이름
	_name = L"리자몽";
	_num = 3;


	//스탯(개체값)
	_pokemonValue.hp = 78;
	_pokemonValue.attack = 84;
	_pokemonValue.defense = 78;
	_pokemonValue.sattack = 109;
	_pokemonValue.sdefense = 85;
	_pokemonValue.speed = 100;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_FIRE;
	_type[1] = POKEMON_TYPE_FLYING;

	_jump = true;
}

Charizard::~Charizard()
{
}

HRESULT Charizard::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("charizard_idle",
		L"img/pokemon/3. charizard/idle.png", 198, 660, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("charizard_move",
		L"img/pokemon/3. charizard/move.png", 264, 660, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("charizard_attack",
		L"img/pokemon/3. charizard/attack.png", 328, 726, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("charizard_sattack",
		L"img/pokemon/3. charizard/sattack.png", 160, 704, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("charizard_hurt",
		L"img/pokemon/3. charizard/hurt.png", 62, 704, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("charizard_sleep",
		L"img/pokemon/3. charizard/sleep.png", 108, 58, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("charizard_default",
		L"img/pokemon/3. charizard/default.png", 66, 660, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("charizard_portrait",
		L"img/pokemon/3. charizard/portrait.png", 40, 40);

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
	_skill.push_back(2);
	_skill.push_back(5);
	_skill.push_back(7);
	_skill.push_back(8);
	_skill.push_back(9);
	_skill.push_back(14);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(19);
	_skill.push_back(22);

	return S_OK;
}