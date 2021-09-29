#include "stdafx.h"
#include "ThunderFang.h"

HRESULT ThunderFang::init(Player* player)
{
	Skill::init(player);
	_name = L"번개엄니";
	_skillNum = 7;
	_damage = 65;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_ELECTRIC;
	_scale = SS_FRONT;

	return S_OK;
}

void ThunderFang::release()
{
}

void ThunderFang::useSkill()
{
	Skill::useSkill();

	_thunderFangEffect = new EF_ThunderFang;
	_thunderFangEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_thunderFangEffect);
}
