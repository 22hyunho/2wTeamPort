#include "stdafx.h"
#include "Apple.h"

HRESULT Apple::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("apple", L"img/item/food/apple1.png", ITEMSIZE, ITEMSIZE);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);
	_name = L"사과";
	_itemInfo = L"배고픔이 회복된다";
	//_itemInfoLong = L "";
	_type = ITEM_FOOD;
	_num = 1;
	_value = 50;

	//IMAGEMANAGER->addDImage("gold_apple", L"img/item/food/apple2.png", ITEMSIZE, ITEMSIZE);	//황금사과
	//IMAGEMANAGER->addDImage("rot_apple", L"img/item/food/apple3.png", ITEMSIZE, ITEMSIZE);	//썩은

	return S_OK;
}

void Apple::release()
{
}

void Apple::update()
{
}