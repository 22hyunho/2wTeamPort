#include "stdafx.h"
#include "EF_IceFang.h"

HRESULT EF_IceFang::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("IceFang", L"img/effect/IceFang.png", 1476, 114, 9, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("IceFang");
	return S_OK;
}

void EF_IceFang::release()
{
	SOUNDMANAGER->stop("IceFang");
}

void EF_IceFang::update()
{
}
