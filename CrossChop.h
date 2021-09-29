#pragma once
#include "Skill.h"
#include "EF_CrossChop.h"

class CrossChop :
	public Skill
{
private :
	EF_CrossChop* _crossChopEffect;

public :
	CrossChop() {};
	~CrossChop() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

