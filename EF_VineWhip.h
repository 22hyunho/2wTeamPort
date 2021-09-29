#pragma once
#include "Effect.h"
class EF_VineWhip :
	public Effect
{
private :

public :
	EF_VineWhip() {};
	~EF_VineWhip() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

