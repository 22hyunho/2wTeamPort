#include "stdafx.h"
#include "EF_WingAttack.h"

HRESULT EF_WingAttack::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("WingAttack", L"img/effect/WingAttack.png", 8160, 160, 51, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 40);
	_renderCount = 0.02f;

	SOUNDMANAGER->play("WingAttack");

	return S_OK;
}

void EF_WingAttack::release()
{
	SOUNDMANAGER->stop("WingAttack");
}

void EF_WingAttack::update()
{
}
