#pragma once
#include "Skill.h"
#include "EF_FireBlast.h"

class FireBlast :
	public Skill
{
private:
	EF_FireBlast* _fireBlastEffect;
public:
	FireBlast() {};
	~FireBlast() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

