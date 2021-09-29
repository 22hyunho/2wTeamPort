#include "stdafx.h"
#include "ResultMenu.h"
#include "Player.h"

HRESULT ResultMenu::init()
{
	//배경 이미지
	_back = IMAGEMANAGER->addDImage(
		"resultMenu_back", L"img/UI/resultMenu/back.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"resultMenu_border", L"img/UI/resultMenu/border.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);

	return S_OK;
}

void ResultMenu::release()
{
}

void ResultMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_A))
		CAMERAMANAGER->setFade(FADEOUT);
}

void ResultMenu::render()
{
	DownMenu::render();

	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();
	//D2D1_RECT_F dest = dRectMakeCenter((screen.left + screen.right) / 2, 145, 200, 200);

	D2D1_RECT_F dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 - 140,
		400, 100);

	WCHAR text[128];
	swprintf_s(text, L"%s(을)를 클리어했다.", TILEMANAGER->getDungeonName().c_str());
	DTDMANAGER->printText(text, dest, 25, true);


	Player* player = (*TURNMANAGER->getAllPlayer())[0];

	//NAME
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 - 50,
		400, 50);
	swprintf_s(text, L"포켓몬 : %s", player->getPokemon()->getName().c_str());
	DTDMANAGER->printText(text, dest, 25);

	//LEVEL, EXP
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2,
		400, 50);
	swprintf_s(text, L"레벨 : %d  \t 경험치 : %d", player->getLevel(), player->getEXP());
	DTDMANAGER->printText(text, dest, 25);

	//HP, SPEED
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 + 50,
		400, 50);
	swprintf_s(text, L"체력 : %d  \t 스피드 : %d",
		player->getRealStat().hp, player->getRealStat().speed);
	DTDMANAGER->printText(text, dest, 25);

	//ATTACK, DEFENSE
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 + 100,
		400, 50);
	swprintf_s(text, L"공격 : %d  \t 방어 : %d",
		player->getRealStat().attack, player->getRealStat().defense);
	DTDMANAGER->printText(text, dest, 25);

	//SATTACK, SDEFENSE
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 + 150,
		400, 50);
	swprintf_s(text, L"특수공격 : %d \t 특수방어 : %d",
		player->getRealStat().sattack, player->getRealStat().sdefense);
	DTDMANAGER->printText(text, dest, 25);
}
