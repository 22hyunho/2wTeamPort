#include "stdafx.h"
#include "VineWhip.h"

HRESULT VineWhip::init(Player * player)
{
	Skill::init(player);
	_name = L"µ¢ÄðÃ¤Âï";
	_skillNum = 23;
	_damage = 45;
	_accuracy = 1.f;
	_currentPP = _maxPP = 25;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void VineWhip::release()
{
}

void VineWhip::useSkill()
{
	Skill::useSkill();

	_vineWhipEffect = new EF_VineWhip;
	_vineWhipEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_vineWhipEffect);
}
