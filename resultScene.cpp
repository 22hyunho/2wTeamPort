#include "stdafx.h"
#include "resultScene.h"

HRESULT resultScene::init(Player * player)
{
	Scene::init(player);

	_back = IMAGEMANAGER->addDImage("loadingBack", L"img/fade_B.png", WINSIZEX, WINSIZEY);
	CAMERAMANAGER->setBackScreenSize(WINSIZEX, WINSIZEY);

	//ui º¯°æ
	UIMANAGER->changeUpMenu("blackMenu");
	UIMANAGER->changeDownMenu("resultMenu");

	SOUNDMANAGER->play("Clear");

	return S_OK;
}

void resultScene::release()
{
	TXTDATA->saveGame(_player);
	DIALOGMANAGER->release();
}

void resultScene::update()
{
	UIMANAGER->update();

	changeScene();
}

void resultScene::render()
{
	_back->render();

	UIMANAGER->renderDown();
}

void resultScene::changeScene()
{
	if (CAMERAMANAGER->getAlpha() == 1.0)
		SCENEMANAGER->changeScene("select");
}
