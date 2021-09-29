#pragma once
#include "Effect.h"
class EF_TriAttack :
	public Effect
{
private :

public :
	EF_TriAttack() {};
	~EF_TriAttack() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

