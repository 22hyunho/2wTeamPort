#pragma once
#include "Item.h"

class TMachine : public Item
{
private:

public:
	TMachine() {};
	~TMachine() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y) = 0;

	//아이템 사용
	virtual void useItem();
};