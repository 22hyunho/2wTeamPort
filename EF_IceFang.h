#pragma once
#include "Effect.h"
class EF_IceFang :
	public Effect
{
private:

public:
	EF_IceFang() {};
	~EF_IceFang() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

