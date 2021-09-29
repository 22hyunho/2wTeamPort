#pragma once
#include "Skill.h"
#include "EF_TriAttack.h"

class TriAttack :
	public Skill
{
private :
	EF_TriAttack* _triAttackEffect;

public :
	TriAttack() {};
	~TriAttack() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

