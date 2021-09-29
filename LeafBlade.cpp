#include "stdafx.h"
#include "LeafBlade.h"

HRESULT LeafBlade::init(Player* player)
{
	Skill::init(player);
	_name = L"리프블레이드";
	_skillNum = 6;
	_damage = 90;
	_accuracy = 1.f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void LeafBlade::release()
{
}

void LeafBlade::useSkill()
{
	Skill::useSkill();

	_leafBladeEffect = new EF_LeafBlade;
	_leafBladeEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_leafBladeEffect);
}
