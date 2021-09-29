#include "stdafx.h"
#include "EF_VineWhip.h"

HRESULT EF_VineWhip::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("VineWhip", L"img/effect/VineWhip.png", 576, 124, 9, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("VineWhip");
	return S_OK;
}

void EF_VineWhip::release()
{
	SOUNDMANAGER->stop("VineWhip");
}

void EF_VineWhip::update()
{
}
