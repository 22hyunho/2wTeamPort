#pragma once
#include "Skill.h"
#include "EF_SheerCold.h"

class SheerCold :
	public Skill
{
private :
	EF_SheerCold* _sheerColdEffect;

public :
	SheerCold() {};
	~SheerCold() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

