#pragma once
#include "Skill.h"
#include "EF_LeafBlade.h"

class LeafBlade :
	public Skill
{
private:
	EF_LeafBlade* _leafBladeEffect;

public:
	LeafBlade() {};
	~LeafBlade() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

