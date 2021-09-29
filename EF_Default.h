#pragma once
#include "Effect.h"

class EF_Default : public Effect
{
public:
	EF_Default() {};
	~EF_Default() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

