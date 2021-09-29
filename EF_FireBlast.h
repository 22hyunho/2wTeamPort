#pragma once
#include "Effect.h"
class EF_FireBlast :
	public Effect
{
private:

public:
	EF_FireBlast() {};
	~EF_FireBlast() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

