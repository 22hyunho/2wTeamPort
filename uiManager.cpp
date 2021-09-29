#include "stdafx.h"
#include "uiManager.h"
#include "MenuHeader.h"

UpMenu* uiManager::_currentUpMenu = NULL;
DownMenu* uiManager::_currentDownMenu = NULL;

HRESULT uiManager::init()
{
	_screen = dRectMake(5 * WINSIZEX / 16, 0, 3 * WINSIZEX / 8, 3 * WINSIZEY / 8);

	_currentUpMenu = NULL;
	_currentDownMenu = NULL;

	//위 메뉴
	addUpMenu("keyMenu", new KeyMenu);
	addUpMenu("statusMenu", new StatusMenu);
	addUpMenu("titleMenu", new TitleMenuU);
	addUpMenu("blackMenu", new BlackMenu);
	//changeUpMenu("statusMenu");

	//아래 메뉴
	addDownMenu("titleMenu", new TitleMenuD);
	addDownMenu("mainMenu", new MainMenu);
	addDownMenu("logMenu", new LogMenu);
	addDownMenu("invenMenu", new InvenMenu);
	addDownMenu("skillMenu", new SkillMenu);
	addDownMenu("resultMenu", new ResultMenu);
	//changeDownMenu("logMenu");

	_open = false;

	return S_OK;
}

void uiManager::release()
{
	//위 메뉴 release
	upMenuIter umiList = _upMenu.begin();

	for (; umiList != _upMenu.end();)
	{
		if (umiList->second != NULL)
		{
			if (umiList->second == _currentUpMenu) umiList->second->release();
			SAFE_DELETE(umiList->second);
			umiList = _upMenu.erase(umiList);
		}
		else ++umiList;
	}

	_upMenu.clear();


	//아래 메뉴 release
	downMenuIter dmiList = _downMenu.begin();

	for (; dmiList != _downMenu.end();)
	{
		if (dmiList->second != NULL)
		{
			if (dmiList->second == _currentDownMenu) dmiList->second->release();
			SAFE_DELETE(dmiList->second);
			dmiList = _downMenu.erase(dmiList);
		}
		else ++dmiList;
	}

	_downMenu.clear();
}

void uiManager::update()
{
	if (_currentUpMenu) _currentUpMenu->update();
	if (_currentDownMenu) _currentDownMenu->update();
}

void uiManager::renderDown()
{
	if (_currentDownMenu) _currentDownMenu->render();
}

void uiManager::renderUp()
{
	if (_currentUpMenu) _currentUpMenu->render();
}

UpMenu * uiManager::addUpMenu(string menuName, UpMenu * menu)
{
	if (!menu) return nullptr;

	_upMenu.insert(make_pair(menuName, menu));

	return menu;
}

DownMenu * uiManager::addDownMenu(string menuName, DownMenu * menu)
{
	if (!menu) return nullptr;

	_downMenu.insert(make_pair(menuName, menu));

	return menu;
}

HRESULT uiManager::changeUpMenu(string menuName)
{
	upMenuIter find = _upMenu.find(menuName);

	if (find == _upMenu.end()) return E_FAIL;

	if (find->second == _currentUpMenu) return S_OK;

	if (SUCCEEDED(find->second->init()))
	{
		//현재(있던) 씬의 릴리즈 함수를 실행해주고
		if (_currentUpMenu) _currentUpMenu->release();

		//바꾸려는 씬을 현재씬으로 체인지
		_currentUpMenu = find->second;

		//CAMERAMANAGER->setFade(FADEIN);

		return S_OK;
	}

	return E_FAIL;
}

HRESULT uiManager::changeDownMenu(string menuName)
{
	if (menuName == "NULL") {
		_currentDownMenu->release();
		_currentDownMenu = NULL;
	}

	downMenuIter find = _downMenu.find(menuName);

	if (find == _downMenu.end()) return E_FAIL;

	if (find->second == _currentDownMenu) return S_OK;

	if (SUCCEEDED(find->second->init()))
	{
		//현재(있던) 씬의 릴리즈 함수를 실행해주고
		if (_currentDownMenu) _currentDownMenu->release();

		//바꾸려는 씬을 현재씬으로 체인지
		_currentDownMenu = find->second;

		//CAMERAMANAGER->setFade(FADEIN);

		return S_OK;
	}

	return E_FAIL;
}
