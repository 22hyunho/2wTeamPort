#pragma once
#include "Skill.h"
#include "EF_ThunderFang.h"

class ThunderFang :
	public Skill
{
private:
	EF_ThunderFang* _thunderFangEffect;

public:
	ThunderFang() {};
	~ThunderFang() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

