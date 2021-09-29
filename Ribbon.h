#pragma once
#include "Item.h"

enum ribbonType
{
	RIBBONTYPE_POWERBAND,
	RIBBONTYPE_SHIELDSCARF,
	//RIBBONTYPE_SPECIALRIBBON,
	//RIBBONTYPE_KETOACIDBAND,
	ENDRIBBONTYPE
};

class Ribbon : public Item
{
private:
	int _ribbonNum;

public:
	Ribbon() {};
	~Ribbon() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();

	//아이템 사용
	void giveItem();
};