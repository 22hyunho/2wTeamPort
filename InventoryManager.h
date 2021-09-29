#pragma once
#include "singletonBase.h"

class item;

class InventoryManager : public singletonBase<InventoryManager>
{
private:
	typedef vector<Item*>			itemList;
	typedef vector<Item*>::iterator	itemListIter; 

private:
	itemList		_vItem;
	//itemListIter	_viItem;
	itemList		_vItemStorage;

	Player* _player;

public:
	InventoryManager() {};
	~InventoryManager() {};

	virtual HRESULT init();
	void release();

	void useItem(int index);

	void addItem(Item* itemName);
	void removeItem(int arrNum);

	void addItemStorage(Item* itemName);
	void removeItemStorage(int arrNum);


	//get
	vector<Item*>* getVItem() { return &_vItem; }
	vector<Item*>* getVitemStorage() { return &_vItemStorage; }
};