#include "stdafx.h"
#include "SkillMenu.h"
#include "Skill.h"

HRESULT SkillMenu::init()
{
	_back = IMAGEMANAGER->addDImage(
		"skillMenu_back", L"img/UI/skillMenu/back1.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_back2 = IMAGEMANAGER->addDImage(
		"skillMenu_back2", L"img/UI/skillMenu/back2.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"skillMenu_border", L"img/UI/skillMenu/border1.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_border2 = IMAGEMANAGER->addDImage(
		"skillMenu_border2", L"img/UI/skillMenu/border2.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_arrow = IMAGEMANAGER->findDImage("selectTri");

	_tuningX = 2 * TILEWIDTH / 3;
	_tuningY = TILEHEIGHT / 2;

	_index = 0;
	_index2 = 0;
	
	_skill = (*TURNMANAGER->getAllPlayer())[0]->getSkill();
	_maxIndex = 0;
	for (int i = 0; i < 4; i++) {
		if (_skill[i])
			_maxIndex++;
	}

	_hidden = false;

	_rc = CAMERAMANAGER->getScreen();

	return S_OK;
}

void SkillMenu::release()
{
}

void SkillMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_UP))
	{
		SOUNDMANAGER->play("Index");
		minusIndex();
	}
	if (KEYMANAGER->isOnceKeyDown(KEY_DOWN))
	{
		SOUNDMANAGER->play("Index");
		plusIndex();
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_B))
	{
		SOUNDMANAGER->play("Cancel");
		if (_hidden) _hidden = false;

		else
		{
			UIMANAGER->changeDownMenu("mainMenu");
		}
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A))
	{
		SOUNDMANAGER->play("Select");
		if (_hidden)
		{
			if (_index2 == SKILL_SELECTMENU_OPTION_USE)
			{
				if (_skill[_index]->getCurrentPP() > 0)
				{
					(*TURNMANAGER->getAllPlayer())[0]->useSkill(_index);

					UIMANAGER->changeDownMenu("logMenu");
					UIMANAGER->setOpen(false);
				}

				if (_skill[_index]->getCurrentPP() <= 0) _hidden = false;
			}

			else if (_index2 == SKILL_SELECTMENU_OPTION_INFO) _hidden = false;
			else if (_index2 == SKILL_SELECTMENU_OPTION_BACK) _hidden = false;
		}

		else _hidden = true;
	}

	_count++;
	if (_count > 20) {
		_opacity = !_opacity;
		_count = 0;
	}
}

void SkillMenu::render()
{
	DownMenu::render();

	printTextLeft();
	printPP();

	if(_hidden)	printTextRight();

	printTextDown();
}

void SkillMenu::printTextLeft()
{
	D2D1_RECT_F leftDest = dRectMake(_rc.left + _tuningX + TILEWIDTH, _rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH * 10, TILEHEIGHT);

	DTDMANAGER->printText((*TURNMANAGER->getAllPlayer())[0]->getPokemon()->getName().c_str(),
		_rc.left + _tuningX + TILEWIDTH * 3 + TILEWIDTH / 2 + 15, _rc.top + _tuningY + 20 + TILEHEIGHT, 200, 100, 25);

	//화살표
	if (!_hidden) _arrow->render(leftDest.left - 20, leftDest.top + _index * TILEHEIGHT, _opacity);

	if(_skill[0])
		DTDMANAGER->printText(_skill[0]->getName().c_str(), leftDest, 25);

	leftDest.top += TILEHEIGHT;
	leftDest.bottom += TILEHEIGHT;

	if(_skill[1])
		DTDMANAGER->printText(_skill[1]->getName().c_str(), leftDest, 25);

	leftDest.top += TILEHEIGHT;
	leftDest.bottom += TILEHEIGHT;

	if(_skill[2])
		DTDMANAGER->printText(_skill[2]->getName().c_str(), leftDest, 25);

	leftDest.top += TILEHEIGHT;
	leftDest.bottom += TILEHEIGHT;

	if(_skill[3])
		DTDMANAGER->printText(_skill[3]->getName().c_str(), leftDest, 25);
}

void SkillMenu::printTextRight()
{
	_back2->render(_rc.left + _tuningX, _rc.top + _tuningY, 0.5);
	_border2->render(_rc.left + _tuningX, _rc.top + _tuningY);
	
	D2D1_RECT_F rightDest = dRectMake(_rc.left + _tuningX + TILEWIDTH * 9 + 25, _rc.top + _tuningY + 12, TILEWIDTH * 10, TILEHEIGHT);

	DTDMANAGER->printText(L"쓴다", rightDest, 25);
	
	rightDest.top += 36;
	rightDest.bottom += 36;

	DTDMANAGER->printText(L"설명", rightDest, 25);

	rightDest.top += 36;
	rightDest.bottom += 36;

	DTDMANAGER->printText(L"돌아간다", rightDest, 25);

	if (_hidden) _arrow->render(rightDest.left - 20, (rightDest.top + TILEHEIGHT / 2 - TILEHEIGHT * 2) + _index2 * 36, _opacity);
}

void SkillMenu::printTextDown()
{
	D2D1_RECT_F downDest = dRectMake(_rc.left + _tuningX + TILEWIDTH, _rc.top + 5 + _tuningY + TILEHEIGHT * 7 + TILEHEIGHT / 2, TILEWIDTH * 10, TILEHEIGHT);

	if(_skill[_index]->getCurrentPP() <= 0) DTDMANAGER->printText(L"PP가 부족합니다", downDest, 25);
}

void SkillMenu::printPP()
{
	D2D1_RECT_F ppDest = dRectMake(_rc.left + _tuningX + TILEWIDTH * 6, _rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2, TILEWIDTH * 10, TILEHEIGHT);
	D2D1_RECT_F ppDest2 = dRectMake(_rc.left + _tuningX + TILEWIDTH * 7, _rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2, TILEWIDTH * 10, TILEHEIGHT);

	WCHAR str[128];
	if (_skill[0]) {
		swprintf_s(str, L"%d /", _skill[0]->getCurrentPP());
		DTDMANAGER->printText(str, ppDest, 25);
		swprintf_s(str, L" %d", _skill[0]->getMaxPP());
		DTDMANAGER->printText(str, ppDest2, 25);
	}

	ppDest.top += TILEHEIGHT;
	ppDest.bottom += TILEHEIGHT;
	ppDest2.top += TILEHEIGHT;
	ppDest2.bottom += TILEHEIGHT;

	if (_skill[1]) {
		swprintf_s(str, L"%d /", _skill[1]->getCurrentPP());
		DTDMANAGER->printText(str, ppDest, 25);
		swprintf_s(str, L" %d", _skill[1]->getMaxPP());
		DTDMANAGER->printText(str, ppDest2, 25);
	}

	ppDest.top += TILEHEIGHT;
	ppDest.bottom += TILEHEIGHT;
	ppDest2.top += TILEHEIGHT;
	ppDest2.bottom += TILEHEIGHT;

	if (_skill[2]) {
		swprintf_s(str, L"%d /", _skill[2]->getCurrentPP());
		DTDMANAGER->printText(str, ppDest, 25);
		swprintf_s(str, L" %d", _skill[2]->getMaxPP());
		DTDMANAGER->printText(str, ppDest2, 25);
	}
	
	ppDest.top += TILEHEIGHT;
	ppDest.bottom += TILEHEIGHT;
	ppDest2.top += TILEHEIGHT;
	ppDest2.bottom += TILEHEIGHT;
	
	if (_skill[3]) {
		swprintf_s(str, L"%d /", _skill[3]->getCurrentPP());
		DTDMANAGER->printText(str, ppDest, 25);
		swprintf_s(str, L" %d", _skill[3]->getMaxPP());
		DTDMANAGER->printText(str, ppDest2, 25);
	}
}

void SkillMenu::plusIndex()
{
	if (!_hidden)
	{
		_index += 1;

		if (_index >= _maxIndex) _index = 0;
	}

	if (_hidden)
	{
		_index2 = (_index2 + 1) % END_SKILL_SELECTMENU_OPTION;
	}
	else _index2 = 0;
}

void SkillMenu::minusIndex()
{
	if (!_hidden)
	{
		_index -= 1;

		if (_index < 0) _index = _maxIndex - 1;
	}

	if (_hidden)
	{
		_index2 = (_index2 - 1 + END_SKILL_SELECTMENU_OPTION) % END_SKILL_SELECTMENU_OPTION;
	}
	else _index2 = 0;
}
