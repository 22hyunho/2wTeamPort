#pragma once
#include "Effect.h"
class EF_SleepPowder :
	public Effect
{
private:

public:
	EF_SleepPowder() {};
	~EF_SleepPowder() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

