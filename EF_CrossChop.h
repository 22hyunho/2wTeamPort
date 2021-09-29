#pragma once
#include "Effect.h"
class EF_CrossChop :
	public Effect
{
private :

public :
	EF_CrossChop() {};
	~EF_CrossChop() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

