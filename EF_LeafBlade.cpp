#include "stdafx.h"
#include "EF_LeafBlade.h"

HRESULT EF_LeafBlade::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("LeafBlade", L"img/effect/LeafBlade.png", 4774, 162, 31, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.01f;

	SOUNDMANAGER->play("LeafBlade");
	return S_OK;
}

void EF_LeafBlade::release()
{
	SOUNDMANAGER->stop("LeafBlade");
}

void EF_LeafBlade::update()
{
}
