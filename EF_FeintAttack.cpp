#include "stdafx.h"
#include "EF_FeintAttack.h"

HRESULT EF_FeintAttack::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("FeintAttack", L"img/effect/FeintAttack.png", 2688, 128, 21, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("FeintAttack");
	return S_OK;
}

void EF_FeintAttack::release()
{
	SOUNDMANAGER->stop("FeintAttack");
}

void EF_FeintAttack::update()
{
}
