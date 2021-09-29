#pragma once
#include "Skill.h"
#include "EF_IceFang.h"

class IceFang :
	public Skill
{
private:
	EF_IceFang* _iceFangEffect;

public:
	IceFang() {};
	~IceFang() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

