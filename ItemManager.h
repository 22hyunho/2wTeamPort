#pragma once
#include "Item.h"
#include <vector>

class ItemManager
{
private:
	typedef vector<Item*>				itemUse;
	typedef vector<Item*>::iterator		itemUseIter;

private:
	itemUse		_vItemAdd;
	itemUseIter	_viItemAdd;

public:
	ItemManager() {};
	~ItemManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void addItem(Item* item);
	void removeItem(int num);

	vector<Item*>* getVItem() { return &_vItemAdd; }
};

