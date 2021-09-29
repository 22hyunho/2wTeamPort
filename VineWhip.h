#pragma once
#include "Skill.h"
#include "EF_VineWhip.h"

class VineWhip :
	public Skill
{
private :
	EF_VineWhip* _vineWhipEffect;

public :
	VineWhip() {};
	~VineWhip() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

