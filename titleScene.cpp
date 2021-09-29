#include "stdafx.h"
#include "titleScene.h"

HRESULT titleScene::init(Player * player)
{
	Scene::init(player);

	//CAMERAMANAGER->setFade(FADEOUT);
	CAMERAMANAGER->setBackScreenSize(WINSIZEX, WINSIZEY);

	D2D1_RECT_F rc_bottom = CAMERAMANAGER->getScreen();
	rc_bottom.left += 3 * WINSIZEX / 16;
	rc_bottom.right += 3 * WINSIZEX / 16;
	rc_bottom.top += 3 * WINSIZEY / 8;
	rc_bottom.bottom += 3 * WINSIZEY / 8;

	D2D1_RECT_F rc_top = UIMANAGER->getScreen();

	STREAMMANAGER->startVideo("title_top", rc_top);
	STREAMMANAGER->startVideo2("title_bottom", rc_bottom);

	_change = false;

	return S_OK;
}

void titleScene::release()
{
	STREAMMANAGER->closeVideo();
	STREAMMANAGER->closeVideo2();
}

void titleScene::update()
{
	if (STREAMMANAGER->getPosition() >= STREAMMANAGER->getLength()) {

		STREAMMANAGER->closeVideo();
		STREAMMANAGER->closeVideo2();
		
		D2D1_RECT_F rc_bottom = CAMERAMANAGER->getScreen();
		rc_bottom.left += 3 * WINSIZEX / 16;
		rc_bottom.right += 3 * WINSIZEX / 16;
		rc_bottom.top += 3 * WINSIZEY / 8;
		rc_bottom.bottom += 3 * WINSIZEY / 8;

		D2D1_RECT_F rc_top = UIMANAGER->getScreen();

		STREAMMANAGER->startVideo("title_top", rc_top);
		STREAMMANAGER->startVideo2("title_bottom", rc_bottom);
	}

	changeScene();
}

void titleScene::render()
{
}

void titleScene::changeScene()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) {
		STREAMMANAGER->closeVideo();
		STREAMMANAGER->closeVideo2();
		CAMERAMANAGER->setFade(FADEOUT);
		_change = true;
	}

	if (_change) {
		if (CAMERAMANAGER->getAlpha() == 1.0)
			SCENEMANAGER->changeScene("main");
	}
}
