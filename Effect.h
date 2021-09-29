#pragma once
#include "PokemonType.h"

enum EFFECTNUMBER
{
	EF_FIREBLAST,
	EF_GUST,
	EF_LIGHTNING,
	EF_ROCKSLIDE
};

class Effect
{
protected:
	RECT _body;
	dImage* _img;
	float _x, _y;
	float _tuningX, _tuningY;
	float _count;
	float _renderCount;
	bool _off;
	int _damage;
	int _scale;
	int _atkType;
	POKEMON_TYPE _type;
	//이펙트에 실 데미지 추가

public:
	Effect() {};
	~Effect() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();

	virtual void controlFrame();

	bool getOff() { return _off; }
	RECT getBody() { return _body; }

	int getDamage() { return _damage; }
	int getScale() { return _scale; }
	int getAtkType() { return _atkType; }

	POKEMON_TYPE getType() { return _type; }
};

