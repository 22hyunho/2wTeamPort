#include "stdafx.h"
#include "StunSpore.h"

HRESULT StunSpore::init(Player* player)
{
	Skill::init(player);
	_name = L"저리가루";
	_skillNum = 13;
	_damage = 0;
	_accuracy = 0.75f;
	_currentPP = _maxPP = 30;
	_atkType = TRANSFORM_STATE;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void StunSpore::release()
{
}

void StunSpore::useSkill()
{
	Skill::useSkill();

	_stunSporeEffect = new EF_StunSpore;
	_stunSporeEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_stunSporeEffect);
}
