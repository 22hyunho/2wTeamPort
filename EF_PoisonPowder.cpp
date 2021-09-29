#include "stdafx.h"
#include "EF_PoisonPowder.h"

HRESULT EF_PoisonPowder::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("PoisonPowder", L"img/effect/PoisonPowder.png", 1496, 128, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 30);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("Powder");
	return S_OK;
}

void EF_PoisonPowder::release()
{
	SOUNDMANAGER->stop("Powder");
}

void EF_PoisonPowder::update()
{
}