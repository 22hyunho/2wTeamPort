#include "stdafx.h"
#include "EF_ShadowClaw.h"

HRESULT EF_ShadowClaw::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("ShadowClaw", L"img/effect/ShadowClaw.png", 1944, 120, 18, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.02f;

	SOUNDMANAGER->play("ShadowClaw");
	return S_OK;
}

void EF_ShadowClaw::release()
{
	SOUNDMANAGER->stop("ShadowClaw");
}

void EF_ShadowClaw::update()
{
}
