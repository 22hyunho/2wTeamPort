#include "stdafx.h"
#include "EF_FireFang.h"

HRESULT EF_FireFang::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("FireFang", L"img/effect/FireFang.png", 1440, 112, 10, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("FireFang");
	return S_OK;
}

void EF_FireFang::release()
{
	SOUNDMANAGER->stop("FireFang");
}

void EF_FireFang::update()
{
}
