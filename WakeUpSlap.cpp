#include "stdafx.h"
#include "WakeUpSlap.h"

HRESULT WakeUpSlap::init(Player* player)
{
	Skill::init(player);
	_name = L"Àá±ú¿ò»´Ä¡±â";
	_skillNum = 21;
	_damage = 70;
	_accuracy = 1.f;
	_currentPP = _maxPP = 10;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIGHTING;
	_scale = SS_FRONT;

	return S_OK;
}

void WakeUpSlap::release()
{
}

void WakeUpSlap::useSkill()
{
	Skill::useSkill();

	_wakeUpSlapEffect = new EF_WakeUpSlap;
	_wakeUpSlapEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_wakeUpSlapEffect);
}
