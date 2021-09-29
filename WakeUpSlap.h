#pragma once
#include "Skill.h"
#include "EF_WakeUpSlap.h"

class WakeUpSlap :
	public Skill
{
private :
	EF_WakeUpSlap* _wakeUpSlapEffect;

public :
	WakeUpSlap() {};
	~WakeUpSlap() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

