#pragma once
#include "Skill.h"
#include "EF_PoisonPowder.h"

class PoisonPowder :
	public Skill
{
private:
	EF_PoisonPowder* _poisonPowderEffect;

public:
	PoisonPowder() {};
	~PoisonPowder() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

