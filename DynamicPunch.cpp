#include "stdafx.h"
#include "DynamicPunch.h"

HRESULT DynamicPunch::init(Player* player)
{
	Skill::init(player);
	_name = L"Æø¹ßÆÝÄ¡";
	_skillNum = 5;
	_damage = 100;
	_accuracy = 0.5f;
	_currentPP = _maxPP = 5;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIGHTING;
	_scale = SS_FRONT;

	return S_OK;
}

void DynamicPunch::release()
{
}

void DynamicPunch::useSkill()
{
	Skill::useSkill();

	_dynamicPunchEffect = new EF_DynamicPunch;
	_dynamicPunchEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_dynamicPunchEffect);
}