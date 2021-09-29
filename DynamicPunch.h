#pragma once
#include "Skill.h"
#include "EF_DynamicPunch.h"

class DynamicPunch :
	public Skill
{
private:
	EF_DynamicPunch* _dynamicPunchEffect;

public:
	DynamicPunch() {};
	~DynamicPunch() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

