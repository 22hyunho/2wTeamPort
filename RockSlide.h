#pragma once
#include "Skill.h"
#include "EF_RockSlide.h"

class RockSlide :
	public Skill
{
private:
	EF_RockSlide* _rockSlideEffect;

public:
	RockSlide() {};
	~RockSlide() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

