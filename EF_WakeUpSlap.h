#pragma once
#include "Effect.h"
class EF_WakeUpSlap :
	public Effect
{
private :

public :
	EF_WakeUpSlap() {};
	~EF_WakeUpSlap() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

