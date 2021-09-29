#pragma once
#include "Effect.h"
class EF_FeintAttack :
	public Effect
{
private :

public :
	EF_FeintAttack() {};
	~EF_FeintAttack() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

