#pragma once
#include "Item.h"

class Scope : public Item
{
	Scope() {};
	~Scope() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();

	//아이템 사용
	void giveItem();
};