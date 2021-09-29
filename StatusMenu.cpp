#include "stdafx.h"
#include "StatusMenu.h"

HRESULT StatusMenu::init()
{
	UpMenu::init();

	//배경 이미지
	_back = IMAGEMANAGER->addDImage(
		"statusMenu_back", L"img/UI/statusMenu/back.png", UPMENU_WIDTH, UPMENU_HEIGHT);
	_baseStatusBox = IMAGEMANAGER->addDImage(
		"statusMenu_baseBox", L"img/UI/statusMenu/baseBox.png", UPMENU_WIDTH / 2, UPMENU_HEIGHT / 2);
	_nullStatusBox = IMAGEMANAGER->addDImage(
		"statusMenu_nullBox", L"img/UI/statusMenu/nullBox.png", UPMENU_WIDTH / 2, UPMENU_HEIGHT / 2);
	_statusNumber = IMAGEMANAGER->addDImage(
		"statusMenu_number", L"img/UI/statusMenu/number.png", 60, 60);

	return S_OK;
}

void StatusMenu::release()
{
}

void StatusMenu::update()
{
}

void StatusMenu::render()
{
	UpMenu::render();

	float width = _screen.right - _screen.left;
	float height = _screen.bottom - _screen.top;

	vector<Player*>* teamList = TURNMANAGER->getAllPlayer();
	vector<Player*>::iterator teamIter;
	int i = 0;

	//뿌릴 위치 생성
	D2D1_RECT_F box[4];
	D2D1_RECT_F port[4];

	box[0] = dRectMake(_screen.left + 5, _screen.top + 5, width / 2 - 10, height / 2 - 10);
	box[1] = dRectMake(_screen.left + 5 + width / 2, _screen.top + 5, width / 2 - 10, height / 2 - 10);
	box[2] = dRectMake(_screen.left + 5, _screen.top + 5 + height / 2, width / 2 - 10, height / 2 - 10);
	box[3] = dRectMake(_screen.left + 5 + width / 2, _screen.top + 5 + height / 2, width / 2 - 10, height / 2 - 10);

	port[0] = dRectMake(box[0].left + 12, box[0].top + 15, 60, 65);
	port[1] = dRectMake(box[1].left + 12, box[1].top + 15, 60, 65);
	port[2] = dRectMake(box[2].left + 12, box[2].top + 15, 60, 65);
	port[3] = dRectMake(box[3].left + 12, box[3].top + 15, 60, 65);

	teamIter = teamList->begin();
	for (; teamIter != teamList->end(); ++teamIter, ++i) {
		//팀 동료가 아니면(== 에너미) break;
		if ((*teamIter)->getPlayerType() > PLAYER_TYPE_TEAM) break;

		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), box[i]);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*teamIter)->getPokemon()->getPortrait()->getBitmap(), port[i]);

		//레벨, 체력 출력
		WCHAR tmp[128];
		swprintf_s(tmp, L"%d", (*teamIter)->getLevel());
		DTDMANAGER->printTextF(tmp, box[i].left + 90, box[i].bottom, 100, 70);
		swprintf_s(tmp, L"%d", (*teamIter)->getCurrentHP());
		DTDMANAGER->printTextF(tmp, box[i].left + 130, box[i].bottom, 100, 70);
		swprintf_s(tmp, L"%d", (*teamIter)->getRealStat().hp);
		DTDMANAGER->printTextF(tmp, box[i].left + 180, box[i].bottom, 100, 70);
	}

	//남은 스테이터스박스 널 박스로 채우기
	for (; i < 4; ++i)
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), box[i]);

	//가운데 넘버링
	D2D1_RECT_F rc = dRectMakeCenter((_screen.left + _screen.right) / 2, (_screen.top + _screen.bottom) / 2, 60, 60);
	DTDMANAGER->getRenderTarget()->DrawBitmap(_statusNumber->getBitmap(), rc);
}
