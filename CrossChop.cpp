#include "stdafx.h"
#include "CrossChop.h"

HRESULT CrossChop::init(Player* player)
{
	Skill::init(player);
	_name = L"Å©·Î½ºÃÏ";
	_skillNum = 16;
	_damage = 100;
	_accuracy = 0.85f;
	_currentPP = _maxPP = 5;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIGHTING;
	_scale = SS_FRONT;

	return S_OK;
}

void CrossChop::release()
{
}

void CrossChop::useSkill()
{
	Skill::useSkill();

	_crossChopEffect = new EF_CrossChop;
	_crossChopEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_crossChopEffect);
}
