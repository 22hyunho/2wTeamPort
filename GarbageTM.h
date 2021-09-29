#pragma once
#include "Item.h"

class GarbageTM : public Item
{
private:

public:
	GarbageTM() {};
	~GarbageTM() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render(float x, float y);

	//아이템 사용
	virtual void useItem();
};