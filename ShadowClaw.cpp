#include "stdafx.h"
#include "ShadowClaw.h"

HRESULT ShadowClaw::init(Player* player)
{
	Skill::init(player);
	_name = L"¼¨µµÅ©·ç";
	_skillNum = 19;
	_damage = 70;
	_accuracy = 1.f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_GHOST;
	_scale = SS_FRONT;

	return S_OK;
}

void ShadowClaw::release()
{
}

void ShadowClaw::useSkill()
{
	Skill::useSkill();

	_shadowClawEffect = new EF_ShadowClaw;
	_shadowClawEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_shadowClawEffect);
}
