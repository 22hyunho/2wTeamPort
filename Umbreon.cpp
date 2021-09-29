#include "stdafx.h"
#include "Umbreon.h"

Umbreon::Umbreon()
{
	//이름
	_name = L"블래키";
	_num = 25;


	//스탯(개체값)
	_pokemonValue.hp = 95;
	_pokemonValue.attack = 65;
	_pokemonValue.defense = 110;
	_pokemonValue.sattack = 60;
	_pokemonValue.sdefense = 130;
	_pokemonValue.speed = 65;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_DARK;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Umbreon::~Umbreon()
{
}

HRESULT Umbreon::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("umbreon_idle",
		L"img/pokemon/25. umbreon/idle.png", 58, 682, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("umbreon_move",
		L"img/pokemon/25. umbreon/move.png", 232, 682, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("umbreon_attack",
		L"img/pokemon/25. umbreon/attack.png", 174, 682, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("umbreon_sattack",
		L"img/pokemon/25. umbreon/sattack.png", 62, 682, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("umbreon_hurt",
		L"img/pokemon/25. umbreon/hurt.png", 62, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("umbreon_sleep",
		L"img/pokemon/25. umbreon/sleep.png", 104, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("umbreon_default",
		L"img/pokemon/25. umbreon/default.png", 58, 682, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("umbreon_portrait",
		L"img/pokemon/25. umbreon/portrait.png", 40, 40);

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
	_skill.push_back(14);
	_skill.push_back(17);
	_skill.push_back(19);
	_skill.push_back(20);
	_skill.push_back(21);

	return S_OK;
}
