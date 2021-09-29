#include "stdafx.h"
#include "FireFang.h"

HRESULT FireFang::init(Player* player)
{
	Skill::init(player);
	_name = L"ºÒ²É¾ö´Ï";
	_skillNum = 8;
	_damage = 65;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIRE;
	_scale = SS_FRONT;

	return S_OK;
}

void FireFang::release()
{
}

void FireFang::useSkill()
{
	Skill::useSkill();

	_fireFangEffect = new EF_FireFang;
	_fireFangEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_fireFangEffect);
}
