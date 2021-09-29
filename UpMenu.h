#pragma once

#define UPMENU_WIDTH	3 * WINSIZEX / 8
#define UPMENU_HEIGHT	3 * WINSIZEY / 8

class UpMenu
{
protected:
	D2D1_RECT_F _screen;
	dImage* _back;

public:
	virtual HRESULT init();
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();
};

