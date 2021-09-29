#include "stdafx.h"
#include "Regirock.h"

Regirock::Regirock()
{
	//이름
	_name = L"레지락";
	_num = 32;


	//스탯(개체값)
	_pokemonValue.hp = 80;
	_pokemonValue.attack = 100;
	_pokemonValue.defense = 200;
	_pokemonValue.sattack = 50;
	_pokemonValue.sdefense = 100;
	_pokemonValue.speed = 50;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_ROCK;
	_type[1] = END_POKEMON_TYPE;

	_jump = true;
}

Regirock::~Regirock()
{
}

HRESULT Regirock::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("regirock_idle_default",
		L"img/pokemon/32. regirock/idle_default.png", 68, 748, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("regirock_move",
		L"img/pokemon/32. regirock/move.png", 272, 748, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("regirock_attack",
		L"img/pokemon/32. regirock/attack.png", 408, 748, 6, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("regirock_sattack",
		L"img/pokemon/32. regirock/sattack.png", 74, 814, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("regirock_hurt",
		L"img/pokemon/32. regirock/hurt.png", 66, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("regirock_sleep",
		L"img/pokemon/32. regirock/sleep.png", 112, 54, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = _stateImage[POKEMON_STATE_IDLE];


	//초상화
	_portrait = IMAGEMANAGER->addDImage("regirock_portrait",
		L"img/pokemon/32. regirock/portrait.png", 40, 40);

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
	_skill.push_back(4);
	_skill.push_back(5);
	_skill.push_back(16);
	_skill.push_back(18);
	_skill.push_back(21);

	return S_OK;
}
