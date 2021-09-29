#pragma once
#include "singletonBase.h"
#include "UpMenu.h"
#include "DownMenu.h"

#define STATUSWIDTH 206

enum UP_MENU {
	UP_MENU_STATUS,
	UP_MENU_CONTROLKEY,
	END_UP_MENU
};

enum DOWN_MENU {
	DOWN_MENU_MAIN,
	END_DOWN_MENU
};

class uiManager : public singletonBase<uiManager>
{
private:
	typedef map<string, UpMenu*>				upMenuList;
	typedef map<string, UpMenu*>::iterator		upMenuIter;

	typedef map<string, DownMenu*>				downMenuList;
	typedef map<string, DownMenu*>::iterator	downMenuIter;

private:
	D2D1_RECT_F _screen;

	//메뉴 리스트
	upMenuList	 _upMenu;
	downMenuList _downMenu;

	//현재 메뉴
	static UpMenu*	 _currentUpMenu;
	static DownMenu* _currentDownMenu;


	bool _open;

public:
	HRESULT init();
	void release();
	void update();
	void renderDown();
	void renderUp();

	UpMenu* addUpMenu(string menuName, UpMenu* menu);
	DownMenu* addDownMenu(string menuName, DownMenu* menu);
	HRESULT changeUpMenu(string menuName);
	HRESULT changeDownMenu(string menuName);





	D2D1_RECT_F getScreen() { return _screen; }

	UpMenu* getCurrentUpMenu() { return _currentUpMenu; }
	DownMenu* getCurrentDownMenu() { return _currentDownMenu; }

	bool getOpen() { return _open; }
	void setOpen(bool open) { _open = open; }
};

