#pragma once
#include "Item.h"

class ThrowItem : public Item
{
private:
	int _throwNum;
	Player* _player;

public:
	ThrowItem() {};
	~ThrowItem() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();
	virtual void render();

	void throwItem(float x, float y, float angle);
	void itemMove();
};
