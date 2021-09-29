#include "stdafx.h"
#include "EF_ThunderFang.h"

HRESULT EF_ThunderFang::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("ThunderFang", L"img/effect/ThunderFang.png", 1024, 132, 8, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("ThunderFang");
	return S_OK;
}

void EF_ThunderFang::release()
{
	SOUNDMANAGER->stop("ThunderFang");
}

void EF_ThunderFang::update()
{
}
