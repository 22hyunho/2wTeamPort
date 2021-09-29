#pragma once
#include "UpMenu.h"

class StatusMenu : public UpMenu
{
private:
	dImage* _baseStatusBox;
	dImage* _nullStatusBox;
	dImage* _statusNumber;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

