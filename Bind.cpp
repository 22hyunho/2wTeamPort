#include "stdafx.h"
#include "Bind.h"

HRESULT Bind::init(Player* player)
{
	Skill::init(player);
	_name = L"Á¶ÀÌ±â";
	_skillNum = 15;
	_damage = 15;
	_accuracy = 0.85f;
	_currentPP = _maxPP = 20;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_NORMAL;
	_scale = SS_FRONT;

	return S_OK;
}

void Bind::release()
{
}

void Bind::useSkill()
{
	Skill::useSkill();

	_bindEffect = new EF_Bind;
	_bindEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_bindEffect);
}
