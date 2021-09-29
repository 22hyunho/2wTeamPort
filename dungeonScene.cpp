#include "stdafx.h"
#include "dungeonScene.h"
#include "Team.h"
#include "Enemy.h"
#include "Apple.h"
#include "Gummy.h"
#include "Ribbon.h"
#include "ThrowItem.h"

HRESULT dungeonScene::init(Player * player)
{
	Scene::init(player);

	CAMERAMANAGER->setBackScreenSize((TILEMANAGER->getWidth() - 1) * TILEWIDTH, (TILEMANAGER->getHeight() - 1) * TILEHEIGHT);

	DIALOGMANAGER->init();
	//TILEMANAGER->init();
	TURNMANAGER->init();

	TURNMANAGER->randomSetting();

	UIMANAGER->changeUpMenu("statusMenu");
	UIMANAGER->changeDownMenu("logMenu");

	COLLISIONMANAGER->init(this);

	Apple* apple;
	apple = new Apple;
	apple->init(25, 15, PI);

	Gummy* jelly;
	jelly = new Gummy;
	jelly->init(26, 15, PI);

	Ribbon* ribbon;
	ribbon = new Ribbon;
	ribbon->init(28, 15, PI);

	ThrowItem* titem;
	titem = new ThrowItem;
	titem->init(27, 15, PI);

	INVENTORYMANAGER->addItem(titem);
	INVENTORYMANAGER->addItem(apple);
	INVENTORYMANAGER->addItem(jelly);

	return S_OK;
}

void dungeonScene::release()
{
	//TILEMANAGER->release();
	TURNMANAGER->release();
}

void dungeonScene::update()
{
	TILEMANAGER->setPlayerX(_player->getX());
	TILEMANAGER->setPlayerY(_player->getY());
	TILEMANAGER->update();

	if (DIALOGMANAGER->getPrint())
		DIALOGMANAGER->update();
	else if ((*TURNMANAGER->getAllPlayer())[0]->getPlayerType() == PLAYER_TYPE_USER) {
		if (UIMANAGER->getOpen())
			UIMANAGER->update();
		else {
			_itemManager->update();
			TURNMANAGER->update();
			EFFECTMANAGER->update();
		}
	}

	changeScene();

	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
}

void dungeonScene::render()
{
	TILEMANAGER->render();

	_itemManager->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	UIMANAGER->renderDown();

	if (DIALOGMANAGER->getPrint())
		DIALOGMANAGER->render();
}

void dungeonScene::changeScene()
{
	if (CAMERAMANAGER->getAlpha() == 1.0) {
		if ((*TURNMANAGER->getAllPlayer())[0]->getPlayerType() != PLAYER_TYPE_USER) {
			TILEMANAGER->stopBGM();
			TILEMANAGER->release();
			DIALOGMANAGER->release();
			SCENEMANAGER->changeScene("main");
		}

		else if (TILEMANAGER->getFloor() == 5) {
			TILEMANAGER->stopBGM();
			TILEMANAGER->release();
			DIALOGMANAGER->release();
			SCENEMANAGER->changeScene("result");
		}

		else
			SCENEMANAGER->changeScene("loading");
	}
}
