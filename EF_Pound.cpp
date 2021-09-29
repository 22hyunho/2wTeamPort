#include "stdafx.h"
#include "EF_Pound.h"

HRESULT EF_Pound::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("Pound", L"img/effect/Pound.png", 2268, 116, 21, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("Pound");

	return S_OK;
}

void EF_Pound::release()
{
	SOUNDMANAGER->stop("Pound");
}

void EF_Pound::update()
{
}
