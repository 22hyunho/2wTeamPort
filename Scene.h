#pragma once
#include "ItemManager.h"
#include <vector>

class Player;

class Scene
{
protected:
	static Player* _player;
	ItemManager* _itemManager;

public:
	Scene() {};
	~Scene() {};

	virtual HRESULT init(Player* player);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void changeScene() = 0;

	ItemManager* getItemManager() { return _itemManager; }
};