#include "stdafx.h"
#include "bossMapScene.h"
#include "Enemy.h"
#include "Apple.h"

HRESULT bossMapScene::init(Player * player)
{
	Scene::init(player);
	_width = 16;
	_height = 18;
	//->init(_width, _height);
	TILEMANAGER->load("bossmap1.map");
	_background = IMAGEMANAGER->addDImage("bossback", L"img/map/bossmap1.png", 768, 864);
	CAMERAMANAGER->setBackScreenSize((_width) * TILEWIDTH, (_height) * TILEHEIGHT);
	TURNMANAGER->init();
	player->initXY(10, 10);
	
	_pokemon1 = new Enemy;
	_pokemon1->init(TILEMANAGER->getBoss(), 25);
	TURNMANAGER->addAllPlayer(_pokemon1);

	_itemManager = new ItemManager;
	_itemManager->init();

	Apple* apple;
	apple = new Apple;
	apple->init(5, 5, PI);

	COLLISIONMANAGER->init(this);
	return S_OK;
}

void bossMapScene::release()
{
}

void bossMapScene::update()
{

	if (UIMANAGER->getOpen())
		UIMANAGER->update();
	else {
		_itemManager->update();
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}
	CAMERAMANAGER->updateScreen(_player->getX(),_player->getY() );
}

void bossMapScene::render()
{
	TILEMANAGER->maprender();
	_background->render(0, 0);
	_itemManager->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();
	
	UIMANAGER->renderDown();
}

void bossMapScene::changeScene()
{
}
