#pragma once
#include "Skill.h"
#include "EF_ShadowClaw.h"

class ShadowClaw :
	public Skill
{
private :
	EF_ShadowClaw* _shadowClawEffect;

public :
	ShadowClaw() {};
	~ShadowClaw() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

