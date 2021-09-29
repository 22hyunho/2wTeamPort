#include "stdafx.h"
#include "Giratina.h"

Giratina::Giratina()
{
	//이름
	_name = L"기라티나";
	_num = 38;


	//스탯(개체값)
	_pokemonValue.hp = 150;
	_pokemonValue.attack = 100;
	_pokemonValue.defense = 120;
	_pokemonValue.sattack = 100;
	_pokemonValue.sdefense = 120;
	_pokemonValue.speed = 90;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_GHOST;
	_type[1] = POKEMON_TYPE_DRAGON;

	_jump = false;
}

Giratina::~Giratina()
{
}

HRESULT Giratina::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("giratina_idle",
		L"img/pokemon/38. giratina/idle.png", 114, 1210, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("giratina_move",
		L"img/pokemon/38. giratina/move.png", 456, 1210, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("giratina_attack",
		L"img/pokemon/38. giratina/attack.png", 228, 1210, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("giratina_sattack",
		L"img/pokemon/38. giratina/sattack.png", 114, 1210, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("giratina_hurt",
		L"img/pokemon/38. giratina/hurt.png", 126, 1386, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("giratina_sleep",
		L"img/pokemon/38. giratina/sleep.png", 172, 76, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("giratina_default",
		L"img/pokemon/38. giratina/default.png", 114, 1210, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("giratina_portrait",
		L"img/pokemon/38. giratina/portrait.png", 40, 40);

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
	_skill.push_back(5);
	_skill.push_back(14);
	_skill.push_back(16);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(19);
	_skill.push_back(20);
	_skill.push_back(22);

	return S_OK;
}
