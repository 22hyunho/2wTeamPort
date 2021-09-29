#include "stdafx.h"
#include "DracoMeteor.h"

HRESULT DracoMeteor::init(Player * player)
{
	Skill::init(player);
	_name = L"¿ë¼º±º";
	_skillNum = 26;
	_damage = 130;
	_accuracy = 0.9f;
	_currentPP = _maxPP = 5;
	_atkType = SPECIAL_ATTACK;
	_type = POKEMON_TYPE_DRAGON;
	_scale = SS_FRONT;

	return S_OK;
}

void DracoMeteor::release()
{
}

void DracoMeteor::useSkill()
{
	Skill::useSkill();

	_dracoMeteorEffect = new EF_DracoMeteor;
	_dracoMeteorEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_dracoMeteorEffect);
}
