#pragma once
#include "Effect.h"
class EF_DynamicPunch :
	public Effect
{
private:

public:
	EF_DynamicPunch() {};
	~EF_DynamicPunch() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

