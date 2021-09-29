#include "stdafx.h"
#include "EF_SheerCold.h"

HRESULT EF_SheerCold::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("SheerCold", L"img/effect/SheerCold.png", 6588, 254, 27, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("SheerCold");
	return S_OK;
}

void EF_SheerCold::release()
{
	SOUNDMANAGER->stop("SheerCold");
}

void EF_SheerCold::update()
{
}
