#include "stdafx.h"
#include "InventoryManager.h"

HRESULT InventoryManager::init()
{
	return S_OK;
}

void InventoryManager::release()	//sceneManager ¡Ù Âü°í
{
	itemListIter viItem = _vItem.begin();

	for (; viItem != _vItem.end();)
	{
		viItem = _vItem.erase(viItem);
	}

	_vItem.clear();
}

void InventoryManager::useItem(int index)
{
}

void InventoryManager::addItem(Item* itemName)
{
	_vItem.push_back(itemName);
}

void InventoryManager::removeItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);
}

void InventoryManager::addItemStorage(Item* itemName)
{
	_vItemStorage.push_back(itemName);
}

void InventoryManager::removeItemStorage(int arrNum)
{
	_vItemStorage.erase(_vItemStorage.begin() + arrNum);
}
