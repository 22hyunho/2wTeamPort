#pragma once
#include "Effect.h"
class EF_FireFang :
	public Effect
{
private:

public:
	EF_FireFang() {};
	~EF_FireFang() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

