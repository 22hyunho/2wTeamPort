#pragma once
#include "Skill.h"
#include "EF_MetalClaw.h"

class MetalClaw :
	public Skill
{
private:
	EF_MetalClaw* _metalClawEffect;

public:
	MetalClaw() {};
	~MetalClaw() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

