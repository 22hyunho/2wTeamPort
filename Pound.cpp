#include "stdafx.h"
#include "Pound.h"

HRESULT Pound::init(Player* player)
{
	Skill::init(player);
	_name = L"¸·Ä¡±â";
	_skillNum = 10;
	_damage = 40;
	_accuracy = 1.f;
	_currentPP = _maxPP = 35;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_NORMAL;
	_scale = SS_FRONT;

	return S_OK;
}

void Pound::release()
{
}

void Pound::useSkill()
{
	Skill::useSkill();

	_poundEffect = new EF_Pound;
	_poundEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_poundEffect);
}
