#pragma once
#include "Effect.h"
class EF_SheerCold :
	public Effect
{
private :

public :
	EF_SheerCold() {};
	~EF_SheerCold() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

