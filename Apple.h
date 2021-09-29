#pragma once
#include "Item.h"

class Apple : public Item
{
private:

public:
	Apple() {};
	~Apple() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();

};