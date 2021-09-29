#include "stdafx.h"
#include "EF_RockSmash.h"

HRESULT EF_RockSmash::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("RockSmash", L"img/effect/RockSmash.png", 1562, 110, 11, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("RockSmash");
	return S_OK;
}

void EF_RockSmash::release()
{
	SOUNDMANAGER->stop("RockSmash");
}

void EF_RockSmash::update()
{
}
