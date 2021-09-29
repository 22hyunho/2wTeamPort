#pragma once
#include "Skill.h"
#include "EF_Pound.h"

class Pound :
	public Skill
{
private:
	EF_Pound* _poundEffect;

public:
	Pound() {};
	~Pound() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

