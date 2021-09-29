#include "stdafx.h"
#include "Dragonair.h"

Dragonair::Dragonair()
{
	//이름
	_name = L"신뇽";
	_num = 14;


	//스탯(개체값)
	_pokemonValue.hp = 61;
	_pokemonValue.attack = 84;
	_pokemonValue.defense = 65;
	_pokemonValue.sattack = 70;
	_pokemonValue.sdefense = 70;
	_pokemonValue.speed = 70;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_DRAGON;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Dragonair::~Dragonair()
{
}

HRESULT Dragonair::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("dragonair_idle_move",
		L"img/pokemon/14. dragonair/idle_move.png", 258, 836, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("dragonair_attack",
		L"img/pokemon/14. dragonair/attack.png", 640, 1188, 5, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("dragonair_sattack",
		L"img/pokemon/14. dragonair/sattack.png", 192, 946, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("dragonair_hurt",
		L"img/pokemon/14. dragonair/hurt.png", 60, 704, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("dragonair_sleep",
		L"img/pokemon/14. dragonair/sleep.png", 88, 64, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("dragonair_default",
		L"img/pokemon/14. dragonair/default.png", 86, 836, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("dragonair_portrait",
		L"img/pokemon/14. dragonair/portrait.png", 40, 40);

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
	_skill.push_back(10);
	_skill.push_back(15);
	_skill.push_back(20);

	return S_OK;
}
