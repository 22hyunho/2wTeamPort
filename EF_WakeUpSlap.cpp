#include "stdafx.h"
#include "EF_WakeUpSlap.h"

HRESULT EF_WakeUpSlap::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("WakeUpSlap", L"img/effect/WakeUpSlap.png", 2576, 100, 23, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("WakeUpSlap");
	return S_OK;
}

void EF_WakeUpSlap::release()
{
	SOUNDMANAGER->stop("WakeUpSlap");
}

void EF_WakeUpSlap::update()
{
}
