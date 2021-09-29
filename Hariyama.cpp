#include "stdafx.h"
#include "Hariyama.h"

Hariyama::Hariyama()
{
	//이름
	_name = L"하리뭉";
	_num = 36;


	//스탯(개체값)
	_pokemonValue.hp = 144;
	_pokemonValue.attack = 120;
	_pokemonValue.defense = 60;
	_pokemonValue.sattack = 40;
	_pokemonValue.sdefense = 60;
	_pokemonValue.speed = 50;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_FIGHTING;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Hariyama::~Hariyama()
{
}

HRESULT Hariyama::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("hariyama_idle",
		L"img/pokemon/36. hariyama/idle.png", 132, 726, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("hariyama_move",
		L"img/pokemon/36. hariyama/move.png", 264, 726, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("hariyama_attack",
		L"img/pokemon/36. hariyama/attack.png", 264, 726, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("hariyama_sattack",
		L"img/pokemon/36. hariyama/sattack.png", 66, 726, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("hariyama_hurt",
		L"img/pokemon/36. hariyama/hurt.png", 66, 726, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("hariyama_sleep",
		L"img/pokemon/36. hariyama/sleep.png", 100, 54, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("hariyama_default",
		L"img/pokemon/36. hariyama/default.png", 66, 726, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("hariyama_portrait",
		L"img/pokemon/36. hariyama/portrait.png", 40, 40);

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
	_skill.push_back(5);
	_skill.push_back(10);
	_skill.push_back(16);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(21);

	return S_OK;
}
