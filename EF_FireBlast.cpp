#include "stdafx.h"
#include "EF_FireBlast.h"

HRESULT EF_FireBlast::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("FireBlast", L"img/effect/FireBlast.png", 2640, 120, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("FireBlast");
	return S_OK;
}

void EF_FireBlast::release()
{
	SOUNDMANAGER->stop("FireBlast");
}

void EF_FireBlast::update()
{
}
