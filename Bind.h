#pragma once
#include "Skill.h"
#include "EF_Bind.h"

class Bind :
	public Skill
{
private :
	EF_Bind* _bindEffect;

public :
	Bind() {};
	~Bind() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

