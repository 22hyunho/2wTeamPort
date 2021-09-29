#include "stdafx.h"
#include "EF_DracoMeteor.h"

HRESULT EF_DracoMeteor::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("DracoMeteor", L"img/effect/DracoMeteor.png", 9248, 282, 32, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2 + 90);
	_tuningY = -(_img->getFrameHeight() / 2 + 90);
	_renderCount = 0.02f;

	SOUNDMANAGER->play("DracoMeteor");
	return S_OK;
}

void EF_DracoMeteor::release()
{
	SOUNDMANAGER->stop("DracoMeteor");
}

void EF_DracoMeteor::update()
{
}
