#pragma once
#include "Skill.h"
#include "EF_FireFang.h"

class FireFang :
	public Skill
{
private:
	EF_FireFang* _fireFangEffect;

public:
	FireFang() {};
	~FireFang() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

