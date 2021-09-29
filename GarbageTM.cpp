#include "stdafx.h"
#include "GarbageTM.h"

HRESULT GarbageTM::init(float x, float y)
{
	_img = IMAGEMANAGER->addDImage("used_tm", L"img/item/thing/tm3.png", ITEMSIZE, ITEMSIZE);

	_name = L"æ≤∑π±‚TM";

	return S_OK;
}

void GarbageTM::release()
{
}

void GarbageTM::update()
{
}

void GarbageTM::render(float x, float y)
{
}

void GarbageTM::useItem()
{
}
