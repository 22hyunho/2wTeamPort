#include "stdafx.h"
#include "Scene.h"

Player* Scene::_player = NULL;

HRESULT Scene::init(Player * player)
{
	_player = player;

	_itemManager = new ItemManager;
	_itemManager->init();

	TURNMANAGER->init(_itemManager);

	return S_OK;
}