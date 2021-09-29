#pragma once
#include "Skill.h"
#include "EF_Default.h"

class DefaultAttack : public Skill
{
private:
	Effect* _defaultEffect;

public:
	DefaultAttack() {};
	~DefaultAttack() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

