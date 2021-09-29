#pragma once
#include "Effect.h"
class EF_PoisonPowder :
	public Effect
{
private:

public:
	EF_PoisonPowder() {};
	~EF_PoisonPowder() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

