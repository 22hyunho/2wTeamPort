#include "stdafx.h"
#include "mapToolScene.h"
#include "Enemy.h"
HRESULT mapToolScene::init(Player* player)
{
	Scene::init(player);
	_width = 8;
	_height = 10;
	CAMERAMANAGER->setBackScreenSize(TILEWIDTH*_width, TILEHEIGHT*_height);
	TILEMANAGER->setWidth(_width);
	TILEMANAGER->setHeight(_height);
	_maptool = new Maptool;
	_maptool->init();
	
	x = 0;
	y = 0;

	return S_OK;
}

void mapToolScene::release()
{
}

void mapToolScene::update()
{
	_maptool->update();
	if (KEYMANAGER->isStayKeyDown('W'))y-=1;
	if (KEYMANAGER->isStayKeyDown('A'))x-=1;
	if (KEYMANAGER->isStayKeyDown('S'))y+=1;
	if (KEYMANAGER->isStayKeyDown('D'))x+=1;

	if (x <= 0)x = 0;
	if (y <= 0)y = 0;
	if (x >= TILEWIDTH * _width)x = TILEWIDTH*_width;
	if (y >= TILEHEIGHT * _height)y = TILEHEIGHT*_height;
	CAMERAMANAGER->updateScreen(x, y);
}

void mapToolScene::render()
{
	
	
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	
	_maptool->render();
if (PRINTMANAGER->isDebug())
{
	WCHAR str[128];
	swprintf_s(str, L"_height: %d, _width: %d", _height, _width);
	DTDMANAGER->printText(str, _ptMouse.x, _ptMouse.y, 150, 0);
	swprintf_s(str, L"x: %d, y: %d, type: %d", _ptMouse.x, _ptMouse.y,_maptool->getType());
	DTDMANAGER->printText(str, _ptMouse.x, _ptMouse.y, 150, 200);
	_maptool->minimap();
}

}

void mapToolScene::changeScene()
{
}
