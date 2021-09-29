#include "stdafx.h"
#include "dungeonSelectScene.h"

HRESULT dungeonSelectScene::init(Player * player)
{
	_width = 11;
	_height = 7;

	CAMERAMANAGER->setBackScreenSize(TILEWIDTH * _width, TILEHEIGHT * _height);
	CAMERAMANAGER->updateScreen(0, 0);
	_background = IMAGEMANAGER->addDImage("dungeonSelect", L"img/map/dungeonmap.png", 528, 336);

	_x = 0;
	_y = 0;
	
	//TURNMANAGER->init();
	player->initXY(0, 0);
	_player->resetHP();
	_player->resetPP();

	_selector = RectMake(_x,_y, 12, 12);
	_d0 = RectMake(72, 72, 24, 24);
	_d1 = RectMake(72, 200, 24, 24);
	_d2 = RectMake(72, 264, 48, 48);
	_d3 = RectMake(192, 180, 24, 24);
	_d4 = RectMake(306, 60, 24, 24);
	_d5 = RectMake(300, 120, 24, 24);
	_d6 = RectMake(294, 288, 24, 24);
	_d7 = RectMake(330, 288, 24, 24);

	_change = false;

	UIMANAGER->changeUpMenu("statusMenu");
	UIMANAGER->changeDownMenu("NULL");

	SOUNDMANAGER->play("select");

	return S_OK;
}

void dungeonSelectScene::release()
{
	SOUNDMANAGER->stop("select");
}

void dungeonSelectScene::update()
{
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT))_x += 5;
	else if (KEYMANAGER->isStayKeyDown(KEY_LEFT))_x -= 5;
	if (KEYMANAGER->isStayKeyDown(KEY_UP))_y -= 5;
	else if (KEYMANAGER->isStayKeyDown(KEY_DOWN))_y += 5;

	if (KEYMANAGER->isOnceKeyDown(VK_F10))
		TXTDATA->saveGame(_player);

	if (_x <= 0)_x = 0;
	if (_y <= 0)_y = 0;
	if (_x >= TILEWIDTH * _width)_x = TILEWIDTH * _width;
	if (_y >= TILEHEIGHT * _height)_y = TILEHEIGHT * _height;
	
	changeScene();

	_selector = RectMake(_x, _y, 12, 12);
}

void dungeonSelectScene::render()
{
	_background->render(0, 0);

	DTDMANAGER->Rectangle(_d0);
	DTDMANAGER->Rectangle(_d1);
	DTDMANAGER->Rectangle(_d2);
	DTDMANAGER->Rectangle(_d3);
	DTDMANAGER->Rectangle(_d4);
	DTDMANAGER->Rectangle(_d5);
	DTDMANAGER->Rectangle(_d6);
	DTDMANAGER->Rectangle(_d7);
	DTDMANAGER->Rectangle(_selector);
}

void dungeonSelectScene::changeScene()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_A)) {
		SOUNDMANAGER->play("Select");
		RECT tmp;
		if (IntersectRect(&tmp, &_d0, &_selector))
		{
			TILEMANAGER->init(151, 151, 6);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d1, &_selector))
		{
			TILEMANAGER->init(151, 151, 7);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d2, &_selector))
		{
			TILEMANAGER->init(151, 151, 2);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d3, &_selector))
		{
			TILEMANAGER->init(151, 151, 1);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d4, &_selector))
		{
			TILEMANAGER->init(151, 151, 4);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d5, &_selector))
		{
			TILEMANAGER->init(151, 151, 0);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d6, &_selector))
		{
			TILEMANAGER->init(151, 151, 5);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
		else if (IntersectRect(&tmp, &_d7, &_selector))
		{
			TILEMANAGER->init(151, 151, 3);
			CAMERAMANAGER->setFade(FADEOUT);
			_change = true;
		}
	}

	if (_change) {
		if (CAMERAMANAGER->getAlpha() == 1.0)
			SCENEMANAGER->changeScene("loading");
	}
}
