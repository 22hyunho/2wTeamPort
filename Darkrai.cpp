#include "stdafx.h"
#include "Darkrai.h"

Darkrai::Darkrai()
{
	//이름
	_name = L"다크라이";
	_num = 19;


	//스탯(개체값)
	_pokemonValue.hp = 70;
	_pokemonValue.attack = 90;
	_pokemonValue.defense = 90;
	_pokemonValue.sattack = 135;
	_pokemonValue.sdefense = 90;
	_pokemonValue.speed = 125;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_DARK;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Darkrai::~Darkrai()
{
}

HRESULT Darkrai::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("darkrai_idle",
		L"img/pokemon/19. darkrai/idle.png", 330, 1012, 5, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("darkrai_move",
		L"img/pokemon/19. darkrai/move.png", 264, 792, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("darkrai_attack",
		L"img/pokemon/19. darkrai/attack.png", 328, 990, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("darkrai_sattack",
		L"img/pokemon/19. darkrai/sattack.png", 82, 990, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("darkrai_hurt",
		L"img/pokemon/19. darkrai/hurt.png", 76, 836, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("darkrai_sleep",
		L"img/pokemon/19. darkrai/sleep.png", 108, 62, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("darkrai_default",
		L"img/pokemon/19. darkrai/default.png", 66, 946, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("darkrai_portrait",
		L"img/pokemon/19. darkrai/portrait.png", 40, 40);

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
	_skill.push_back(10);
	_skill.push_back(14);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(19);
	_skill.push_back(20);
	_skill.push_back(21);

	return S_OK;
}