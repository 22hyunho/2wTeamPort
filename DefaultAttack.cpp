#include "stdafx.h"
#include "DefaultAttack.h"

HRESULT DefaultAttack::init(Player * player)
{
	Skill::init(player);

	_name = L"기본공격";
	_skillNum = 0;
	_damage = 25;
	_accuracy = 1.0f;
	_currentPP = _maxPP = 0;
	_atkType = PHYSICAL_ATTACK;
	_type = END_POKEMON_TYPE;
	_scale = SS_FRONT;

	return S_OK;
}

void DefaultAttack::release()
{
}

void DefaultAttack::useSkill()
{
	Skill::useSkill();

	_defaultEffect = new EF_Default;
	_defaultEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_defaultEffect);
}
