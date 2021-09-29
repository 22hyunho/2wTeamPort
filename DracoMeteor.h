#pragma once
#include "Skill.h"
#include "EF_DracoMeteor.h"

class DracoMeteor :
	public Skill
{
private :
	EF_DracoMeteor* _dracoMeteorEffect;

public :
	DracoMeteor() {};
	~DracoMeteor() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

