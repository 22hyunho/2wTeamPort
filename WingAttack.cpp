#include "stdafx.h"
#include "WingAttack.h"

HRESULT WingAttack::init(Player* player)
{
	Skill::init(player);
	_name = L"날개치기";
	_skillNum = 22;
	_damage = 60;
	_accuracy = 1.f;
	_currentPP = _maxPP = 35;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FLYING;
	_scale = SS_FRONT;

	return S_OK;
}

void WingAttack::release()
{
}

void WingAttack::useSkill()
{
	Skill::useSkill();

	_wingAttackEffect = new EF_WingAttack;
	_wingAttackEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_wingAttackEffect);
}
