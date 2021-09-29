#pragma once
#include "Skill.h"
#include "EF_FeintAttack.h"

class FeintAttack :
	public Skill
{
private :
	EF_FeintAttack* _feintAttackEffect;

public :
	FeintAttack() {};
	~FeintAttack() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

