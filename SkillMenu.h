#pragma once
#include "DownMenu.h"

#define SKILLMENU_WIDTH		624
#define SKILLMENU_HEIGHT	528

enum SKILLMENU_OPTION {
	SKILLMENU_OPTION_FIRST,
	SKILLMENU_OPTION_SECOND,
	SKILLMENU_OPTION_THIRD,
	SKILLMENU_OPTION_FOURTH,
	END_SKILLMENU_OPTION
};

enum SKILL_SELECTMENU_OPTION {
	SKILL_SELECTMENU_OPTION_USE,
	SKILL_SELECTMENU_OPTION_INFO,
	SKILL_SELECTMENU_OPTION_BACK,
	END_SKILL_SELECTMENU_OPTION
};

class SkillMenu : public DownMenu
{
private:
	Skill** _skill;

	dImage* _back2;
	dImage* _border2;

	D2D1_RECT_F _rc;

	int _maxIndex;
	int _index2;

	bool _opacity;
	int _count;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void printTextLeft();
	void printTextRight();
	void printTextDown();

	void printPP();

	void plusIndex();
	void minusIndex();
};

