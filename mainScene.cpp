#include "stdafx.h"
#include "mainScene.h"

HRESULT mainScene::init(Player * player)
{
	Scene::init(player);

	CAMERAMANAGER->setBackScreenSize(687, 562);
	CAMERAMANAGER->updateScreen(0, 0);

	TURNMANAGER->addAllPlayer(player);

	//배경 이미지
	IMAGEMANAGER->addDImage("mainImage1", L"img/title/1.png", 256, 192);
	IMAGEMANAGER->addDImage("mainImage2", L"img/title/2.png", 256, 192);
	IMAGEMANAGER->addDImage("mainImage3", L"img/title/3.png", 256, 192);
	IMAGEMANAGER->addDImage("mainImage4", L"img/title/4.png", 256, 192);
	IMAGEMANAGER->addDImage("mainImage5", L"img/title/5.png", 256, 192);
	IMAGEMANAGER->addDImage("mainImage6", L"img/title/6.png", 256, 192);
	IMAGEMANAGER->addDImage("mainImage7", L"img/title/7.png", 256, 192);

	char name[128];
	sprintf_s(name, "mainImage%d", RND->getInt(7) + 1);
	_currentImage = IMAGEMANAGER->findDImage(name);

	UIMANAGER->changeUpMenu("titleMenu");
	UIMANAGER->changeDownMenu("titleMenu");

	SOUNDMANAGER->play("mainBGM");

	return S_OK;
}

void mainScene::release()
{
	SOUNDMANAGER->stop("mainBGM");
}

void mainScene::update()
{
	UIMANAGER->update();

	changeScene();
}

void mainScene::render()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	_currentImage->render(rc.left, rc.top, rc.left, rc.top,
		rc.right - rc.left, rc.bottom - rc.top);

	UIMANAGER->renderDown();
}

void mainScene::changeScene()
{
	if (CAMERAMANAGER->getAlpha() == 1.0) {
		//푸키몬이 있으면
		if(_player->getPokemon())
			SCENEMANAGER->changeScene("select");
		//없으면
		else {

		}
	}
}
