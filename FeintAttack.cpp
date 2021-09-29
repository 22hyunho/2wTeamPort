#include "stdafx.h"
#include "FeintAttack.h"

HRESULT FeintAttack::init(Player* player)
{
	Skill::init(player);
	_name = L"속여때리기";
	_skillNum = 17;
	_damage = 60;
	_accuracy = 1.f;
	_currentPP = _maxPP = 20;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_DARK;
	_scale = SS_FRONT;

	return S_OK;
}

void FeintAttack::release()
{
}

void FeintAttack::useSkill()
{
	Skill::useSkill();

	_feintAttackEffect = new EF_FeintAttack;
	_feintAttackEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_feintAttackEffect);
}
