#include "stdafx.h"
#include "Ivysaur.h"

Ivysaur::Ivysaur()
{
	//이름
	_name = L"이상해풀";
	_num = 8;


	//스탯(개체값)
	_pokemonValue.hp = 60;
	_pokemonValue.attack = 62;
	_pokemonValue.defense = 63;
	_pokemonValue.sattack = 80;
	_pokemonValue.sdefense = 80;
	_pokemonValue.speed = 60;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_GRASS;
	_type[1] = POKEMON_TYPE_POISON;

	_jump = false;
}

Ivysaur::~Ivysaur()
{
}

HRESULT Ivysaur::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("ivysaur_idle",
		L"img/pokemon/8. ivysaur/idle.png", 150, 484, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("ivysaur_move",
		L"img/pokemon/8. ivysaur/move.png", 200, 506, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("ivysaur_attack",
		L"img/pokemon/8. ivysaur/attack.png", 92, 506, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("ivysaur_sattack",
		L"img/pokemon/8. ivysaur/sattack.png", 92, 572, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("ivysaur_hurt",
		L"img/pokemon/8. ivysaur/hurt.png", 50, 484, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("ivysaur_sleep",
		L"img/pokemon/8. ivysaur/sleep.png", 88, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("ivysaur_default",
		L"img/pokemon/8. ivysaur/default.png", 50, 484, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("ivysaur_portrait",
		L"img/pokemon/8. ivysaur/portrait.png", 40, 40);

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
	_skill.push_back(6);
	_skill.push_back(11);
	_skill.push_back(12);
	_skill.push_back(13);
	_skill.push_back(15);
	_skill.push_back(23);

	return S_OK;
}
