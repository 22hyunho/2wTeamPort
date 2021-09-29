#include "stdafx.h"
#include "Waterfall.h"

HRESULT Waterfall::init(Player * player)
{
	Skill::init(player);
	_name = L"ÆøÆ÷¿À¸£±â";
	_skillNum = 24;
	_damage = 80;
	_accuracy = 1.f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_WATER;
	_scale = SS_FRONT;

	return S_OK;
}

void Waterfall::release()
{
}

void Waterfall::useSkill()
{
	Skill::useSkill();

	_waterfallEffect = new EF_Waterfall;
	_waterfallEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_waterfallEffect);
}
