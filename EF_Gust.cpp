#include "stdafx.h"
#include "EF_Gust.h"

HRESULT EF_Gust::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("Gust", L"img/effect/Gust.png", 5824, 160, 52, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 40);
	_renderCount = 0.02f;

	SOUNDMANAGER->play("Gust");
	return S_OK;
}

void EF_Gust::release()
{
	SOUNDMANAGER->stop("Gust");
}

void EF_Gust::update()
{
}
