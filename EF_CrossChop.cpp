#include "stdafx.h"
#include "EF_CrossChop.h"

HRESULT EF_CrossChop::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("CrossChop", L"img/effect/CrossChop.png", 504, 92, 6, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	SOUNDMANAGER->play("CrossChop");
	return S_OK;
}

void EF_CrossChop::release()
{
	SOUNDMANAGER->stop("CrossChop");
}

void EF_CrossChop::update()
{
}
