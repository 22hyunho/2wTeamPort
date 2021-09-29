#pragma once
#include "Effect.h"
class EF_ThunderFang :
	public Effect
{
private:

public:
	EF_ThunderFang() {};
	~EF_ThunderFang() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

