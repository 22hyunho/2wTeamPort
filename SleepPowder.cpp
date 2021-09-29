#include "stdafx.h"
#include "SleepPowder.h"

HRESULT SleepPowder::init(Player* player)
{
	Skill::init(player);
	_name = L"수면가루";
	_skillNum = 12;
	_damage = 0;
	_accuracy = 0.75f;
	_currentPP = _maxPP = 15;
	_atkType = TRANSFORM_STATE;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void SleepPowder::release()
{
}

void SleepPowder::useSkill()
{
	Skill::useSkill();

	_sleepPowderEffect = new EF_SleepPowder;
	_sleepPowderEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_sleepPowderEffect);
}
