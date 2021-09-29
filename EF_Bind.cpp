#include "stdafx.h"
#include "EF_Bind.h"

HRESULT EF_Bind::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("Bind", L"img/effect/Bind.png", 1104, 116, 12, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 30);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("Bind");
	return S_OK;
}

void EF_Bind::release()
{
	SOUNDMANAGER->stop("Bind");
}

void EF_Bind::update()
{
}
