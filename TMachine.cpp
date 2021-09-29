#include "stdafx.h"
#include "TMachine.h"

HRESULT TMachine::init(float x, float y)
{
	//일단 둘 다 두고.. 쓰겠으면 분리할게요
	_img = IMAGEMANAGER->addDImage("tm", L"img/item/thing/tm1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("tm2", L"img/item/thing/tm2.png", ITEMSIZE, ITEMSIZE);

	_x = x;
	_y = y;
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	_name = L"기술머신";

	return S_OK;
}

void TMachine::useItem()
{
}
