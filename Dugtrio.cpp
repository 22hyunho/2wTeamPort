#include "stdafx.h"
#include "Dugtrio.h"

Dugtrio::Dugtrio()
{
	//이름
	_name = L"닥트리오";
	_num = 27;


	//스탯(개체값)
	_pokemonValue.hp = 35;
	_pokemonValue.attack = 80;
	_pokemonValue.defense = 50;
	_pokemonValue.sattack = 50;
	_pokemonValue.sdefense = 70;
	_pokemonValue.speed = 120;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_GROUND;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Dugtrio::~Dugtrio()
{
}

HRESULT Dugtrio::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("dugtrio_idle",
		L"img/pokemon/27. dugtrio/idle.png", 66, 660, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("dugtrio_move",
		L"img/pokemon/27. dugtrio/move.png", 258, 858, 3, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("dugtrio_attack",
		L"img/pokemon/27. dugtrio/attack.png", 198, 660, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("dugtrio_sattack",
		L"img/pokemon/27. dugtrio/sattack.png", 132, 660, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("dugtrio_hurt",
		L"img/pokemon/27. dugtrio/hurt.png", 66, 704, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("dugtrio_sleep",
		L"img/pokemon/27. dugtrio/sleep.png", 124, 54, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("dugtrio_default",
		L"img/pokemon/27. dugtrio/default.png", 66, 660, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("dugtrio_portrait",
		L"img/pokemon/27. dugtrio/portrait.png", 40, 40);

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
	_count[POKEMON_STATE_DEFAULT] = 0.8;

	//상태별 미세조정
	_tuningX = 0;
	_tuningY = 0;

	//attack 2차 함수
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);

	//스킬 목록
	_skill.push_back(4);
	_skill.push_back(10);
	_skill.push_back(18);

	return S_OK;
}