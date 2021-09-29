#include "stdafx.h"
#include "TriAttack.h"

HRESULT TriAttack::init(Player* player)
{
	Skill::init(player);
	_name = L"트라이어택";
	_skillNum = 20;
	_damage = 80;
	_accuracy = 1.f;
	_currentPP = _maxPP = 10;
	_atkType = SPECIAL_ATTACK;
	_type = POKEMON_TYPE_NORMAL;
	_scale = SS_FRONT;

	return S_OK;
}

void TriAttack::release()
{
}

void TriAttack::useSkill()
{
	Skill::useSkill();

	_triAttackEffect = new EF_TriAttack;
	_triAttackEffect->init(_x, _y, _finalDamage, _scale, _atkType, _type);
	EFFECTMANAGER->addEffect(_triAttackEffect);
}
