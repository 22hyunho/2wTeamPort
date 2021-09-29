#pragma once
#include "Skill.h"
#include "EF_Waterfall.h"

class Waterfall :
	public Skill
{
private :
	EF_Waterfall* _waterfallEffect;

public :
	Waterfall() {};
	~Waterfall() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

