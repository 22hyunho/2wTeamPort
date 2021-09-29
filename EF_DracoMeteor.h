#pragma once
#include "Effect.h"
class EF_DracoMeteor :
	public Effect
{
private :

public :
	EF_DracoMeteor() {};
	~EF_DracoMeteor() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

