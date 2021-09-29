#pragma once
#include "DownMenu.h"

class ResultMenu : public DownMenu
{
private:

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

