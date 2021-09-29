#include "stdafx.h"
#include "EF_Lightning.h"

HRESULT EF_Lightning::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("Lightning", L"img/effect/Lightning.png", 816, 286, 12, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 130);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("Lightning");
	return S_OK;
}

void EF_Lightning::release()
{
	SOUNDMANAGER->stop("Lightning");
}

void EF_Lightning::update()
{
}
