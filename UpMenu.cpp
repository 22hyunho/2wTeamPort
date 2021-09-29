#include "stdafx.h"
#include "UpMenu.h"

HRESULT UpMenu::init()
{
	_screen = UIMANAGER->getScreen();

	return S_OK;
}

void UpMenu::render()
{
	DTDMANAGER->getRenderTarget()->DrawBitmap(_back->getBitmap(), _screen);
}
