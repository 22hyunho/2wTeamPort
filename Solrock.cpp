#include "stdafx.h"
#include "Solrock.h"

Solrock::Solrock()
{
	//이름
	_name = L"솔록";
	_num = 31;


	//스탯(개체값)
	_pokemonValue.hp = 70;
	_pokemonValue.attack = 95;
	_pokemonValue.defense = 85;
	_pokemonValue.sattack = 55;
	_pokemonValue.sdefense = 65;
	_pokemonValue.speed = 70;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_ROCK;
	_type[1] = POKEMON_TYPE_PSYCHIC;

	_jump = false;
}

Solrock::~Solrock()
{
}

HRESULT Solrock::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("solrock_idle_move",
		L"img/pokemon/31. solrock/idle_move.png", 174, 682, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("solrock_attack",
		L"img/pokemon/31. solrock/attack.png", 116, 682, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("solrock_sattack",
		L"img/pokemon/31. solrock/sattack.png", 58, 682, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("solrock_hurt",
		L"img/pokemon/31. solrock/hurt.png", 58, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("solrock_sleep",
		L"img/pokemon/31. solrock/sleep.png", 76, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("solrock_default",
		L"img/pokemon/31. solrock/default.png", 58, 682, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("solrock_portrait",
		L"img/pokemon/31. solrock/portrait.png", 40, 40);

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
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(20);

	return S_OK;
}
