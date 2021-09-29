#pragma once
#include "Skill.h"
#include "EF_RockSmash.h"

class RockSmash :
	public Skill
{
private :
	EF_RockSmash* _rockSmashEffect;

public :
	RockSmash() {};
	~RockSmash() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

