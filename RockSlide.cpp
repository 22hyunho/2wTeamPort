#include "stdafx.h"
#include "RockSlide.h"

HRESULT RockSlide::init(Player* player)
{
	Skill::init(player);
	_name = L"½ºÅæ»þ¿ö";
	_skillNum = 4;
	_damage = 75;
	_accuracy = 0.9f;
	_currentPP = _maxPP = 10;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_ROCK;
	_scale = SS_FRONT;

	return S_OK;
}

void RockSlide::release()
{
}

void RockSlide::useSkill()
{
	Skill::useSkill();

	_rockSlideEffect = new EF_RockSlide;
	_rockSlideEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_rockSlideEffect);
}
