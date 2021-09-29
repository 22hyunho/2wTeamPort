#include "stdafx.h"
#include "EF_DynamicPunch.h"

HRESULT EF_DynamicPunch::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("DynamicPunch", L"img/effect/DynamicPunch.png", 2714, 112, 23, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("DynamicPunch");
	return S_OK;
}

void EF_DynamicPunch::release()
{
	SOUNDMANAGER->stop("DynamicPunch");
}

void EF_DynamicPunch::update()
{
}
