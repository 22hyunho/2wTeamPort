#include "stdafx.h"
#include "Item.h"

void Item::render()
{
	if (PRINTMANAGER->isDebug())	DTDMANAGER->Rectangle(_body);
	_img->render(_x * TILEWIDTH + TILEWIDTH / 2 - _img->getWidth() / 2, 
		_y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getHeight() / 2);
}

void Item::eatItem(int value)
{
	(*TURNMANAGER->getAllPlayer())[0]->setStarve((*TURNMANAGER->getAllPlayer())[0]->getStarve() + value);
}

/*
void Item::throwItem(float x, float y, float angle)
{
	_x = _fireX = x;
	_y = _fireY = y;

	_angle = angle;
}

void Item::itemMove()
{
	_x += cosf(_angle);
	_y += -sinf(_angle);

	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		ITEMSIZE, ITEMSIZE);
}
*/