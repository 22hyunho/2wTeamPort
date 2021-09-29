#include "stdafx.h"
#include "Crobat.h"

Crobat::Crobat()
{
	//이름
	_name = L"크로뱃";
	_num = 18;


	//스탯(개체값)
	_pokemonValue.hp = 85;
	_pokemonValue.attack = 90;
	_pokemonValue.defense = 80;
	_pokemonValue.sattack = 70;
	_pokemonValue.sdefense = 80;
	_pokemonValue.speed = 130;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_POISON;
	_type[1] = POKEMON_TYPE_FLYING;

	_jump = true;
}

Crobat::~Crobat()
{
}

HRESULT Crobat::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("crobat_idle",
		L"img/pokemon/18. crobat/idle.png", 204, 748, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("crobat_move",
		L"img/pokemon/18. crobat/move.png", 272, 748, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("crobat_attack",
		L"img/pokemon/18. crobat/attack.png", 340, 748, 5, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("crobat_sattack",
		L"img/pokemon/18. crobat/sattack.png", 252, 682, 3, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("crobat_hurt",
		L"img/pokemon/18. crobat/hurt.png", 52, 594, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("crobat_sleep",
		L"img/pokemon/18. crobat/sleep.png", 96, 38, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("crobat_default",
		L"img/pokemon/18. crobat/default.png", 68, 748, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("crobat_portrait",
		L"img/pokemon/18. crobat/portrait.png", 40, 40);

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
	_skill.push_back(7);
	_skill.push_back(8);
	_skill.push_back(9);
	_skill.push_back(10);
	_skill.push_back(17);
	_skill.push_back(22);

	return S_OK;
}
