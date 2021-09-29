#include "stdafx.h"
#include "EF_Waterfall.h"

HRESULT EF_Waterfall::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("Waterfall", L"img/effect/Waterfall.png", 2232, 230, 18, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 50);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("Waterfall");
	return S_OK;
}

void EF_Waterfall::release()
{
	SOUNDMANAGER->stop("Waterfall");
}

void EF_Waterfall::update()
{
}
