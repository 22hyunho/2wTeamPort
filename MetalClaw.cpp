#include "stdafx.h"
#include "MetalClaw.h"

HRESULT MetalClaw::init(Player* player)
{
	Skill::init(player);
	_name = L"¸ÞÅ»Å©·Î¿ì";
	_skillNum = 14;
	_damage = 50;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 35;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_STEEL;
	_scale = SS_FRONT;

	return S_OK;
}

void MetalClaw::release()
{
}

void MetalClaw::useSkill()
{
	Skill::useSkill();

	_metalClawEffect = new EF_MetalClaw;
	_metalClawEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_metalClawEffect);
}
