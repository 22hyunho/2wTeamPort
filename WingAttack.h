#pragma once
#include "Skill.h"
#include "EF_WingAttack.h"

class WingAttack :
	public Skill
{
private :
	EF_WingAttack* _wingAttackEffect;

public :
	WingAttack() {};
	~WingAttack() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

