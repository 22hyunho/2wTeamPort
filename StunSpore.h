#pragma once
#include "Skill.h"
#include "EF_StunSpore.h"

class StunSpore :
	public Skill
{
private:
	EF_StunSpore* _stunSporeEffect;

public:
	StunSpore() {};
	~StunSpore() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

