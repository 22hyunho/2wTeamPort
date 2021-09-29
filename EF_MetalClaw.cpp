#include "stdafx.h"
#include "EF_MetalClaw.h"

HRESULT EF_MetalClaw::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("MetalClaw", L"img/effect/MetalClaw.png", 968, 78, 11, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("MetalClaw");
	return S_OK;
}

void EF_MetalClaw::release()
{
	SOUNDMANAGER->stop("MetalClaw");
}

void EF_MetalClaw::update()
{
}
