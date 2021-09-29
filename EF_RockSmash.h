#pragma once
#include "Effect.h"
class EF_RockSmash :
	public Effect
{
private :

public :
	EF_RockSmash() {};
	~EF_RockSmash() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

