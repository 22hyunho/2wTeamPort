#include "stdafx.h"
#include "InvenMenu.h"
#include "Item.h"

HRESULT InvenMenu::init()
{
	_back = IMAGEMANAGER->addDImage("invenMenu_back", L"img/UI/invenMenu/back1.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_back2 = IMAGEMANAGER->addDImage("invenMenu_back2", L"img/UI/invenMenu/back2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_back3 = IMAGEMANAGER->addDImage("invenMenu_back3", L"img/UI/invenMenu/back3.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);

	_border = IMAGEMANAGER->addDImage("invenMenu_border", L"img/UI/invenMenu/border1.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border2 = IMAGEMANAGER->addDImage("invenMenu_border2", L"img/UI/invenMenu/border2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border3 = IMAGEMANAGER->addDImage("invenMenu_border3", L"img/UI/invenMenu/border3.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);

	_arrow = IMAGEMANAGER->findDImage("selectTri");

	_invItem = INVENTORYMANAGER->getVItem();

	_tuningX = 2 * TILEWIDTH / 3;
	_tuningY = TILEHEIGHT / 2;

	_index = 0;
	_index2 = 0;

	_count = 0;
	
	_player = (*TURNMANAGER->getAllPlayer())[0];
	_rc = CAMERAMANAGER->getScreen();

	return S_OK;
}

void InvenMenu::release()
{
}

void InvenMenu::update()
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
	//if (KEYMANAGER->isOnceKeyDown(KEY_LEFT)) leftIndex();
	//if (KEYMANAGER->isOnceKeyDown(KEY_RIGHT)) rightIndex();

	if (KEYMANAGER->isOnceKeyDown(KEY_B))
	{
		SOUNDMANAGER->play("Cancel");
		if (_hidden) _hidden = false;
		else
		{
			UIMANAGER->changeDownMenu("mainMenu");
			//UIMANAGER->setOpen(false);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A))
	{
		if (_hidden)
		{
			if ((*_invItem)[_index]->getType() == ITEM_HOLD)
			{
				if (_index2 == INVENMENU_GIVE_OPTION_DUMP)
				{
					INVENTORYMANAGER->removeItem(_index);
					UIMANAGER->changeDownMenu("logMenu");
					UIMANAGER->setOpen(false);
					_hidden = false;
				}
				if (_index2 == INVENMENU_GIVE_OPTION_BACK) _hidden = false;	
			}
			else
			{
				if (_index2 == INVENMENU_OPTION_EACH)
				{
					if ((*_invItem)[_index]->getType() == ITEM_FOOD)
					{
						if (_player->getStarve() < 100) ((*_invItem))[_index]->eatItem((*_invItem)[_index]->getValue());
						if (_player->getStarve() >= 100)
						{
							_player->setStarve(100);
						}

						INVENTORYMANAGER->removeItem(_index);
						UIMANAGER->changeDownMenu("logMenu");
						UIMANAGER->setOpen(false);
						_hidden = false;
					}

					else if ((*_invItem)[_index]->getType() == ITEM_THROW)
					{
						INVENTORYMANAGER->removeItem(_index);
						UIMANAGER->changeDownMenu("logMenu");
						UIMANAGER->setOpen(false);
						_hidden = false;
					}
				}

				if (_index2 == INVENMENU_OPTION_DUMP)
				{
					INVENTORYMANAGER->removeItem(_index);
					UIMANAGER->changeDownMenu("logMenu");
					UIMANAGER->setOpen(false);
					_hidden = false;
				}

				if (_index2 == INVENMENU_OPTION_BACK) _hidden = false;
			}
		}

		else _hidden = true; 
	}

	_count++;
	if (_count > 20) {
		_opacity = !_opacity;
		_count = 0;
	}
}

void InvenMenu::render()
{
	DownMenu::render();

	if((*_invItem).size() > 0) printTextLeft();

	if (_hidden)
	{
		if ((*_invItem)[_index]->getType() == ITEM_HOLD)
		{
			printTextRight2();
			if (_index2 == INVENMENU_GIVE_OPTION_INFO) printTextDown();
		}

		else
		{
			printTextRight();
			if (_index2 == INVENMENU_OPTION_INFO) printTextDown();
		}
	}

	printTextDown();
}

void InvenMenu::printTextLeft()
{
	D2D1_RECT_F dest = dRectMake(_rc.left + _tuningX + TILEWIDTH, _rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH * 10, TILEHEIGHT);

	//화살표
	if(!_hidden) _arrow->render(dest.left - 20, dest.top + _index * TILEHEIGHT, _opacity);

	for (_viInvItem = _invItem->begin(); _viInvItem != _invItem->end(); ++_viInvItem)
	{
		(*_viInvItem)->getName();
											//string은 c_str
		DTDMANAGER->printText((*_viInvItem)->getName().c_str(), dest, 25);

		dest.top += TILEHEIGHT;
		dest.bottom += TILEHEIGHT;

		//if (_invItem->size() % 7 == 0) DTDMANAGER->printText((*_viInvItem)->getName().c_str(), dest, 25);
	}
}

void InvenMenu::printTextRight()
{
	D2D1_RECT_F dest3 = dRectMake(_rc.left + _tuningX + TILEWIDTH * 9 + 25, _rc.top + _tuningY + 12,
		TILEWIDTH * 10, TILEHEIGHT);

	_back2->render(_rc.left + _tuningX, _rc.top + _tuningY, 0.5);
	_border2->render(_rc.left + _tuningX, _rc.top + _tuningY);

	if ((*_invItem)[_index]->getType() == ITEM_FOOD) DTDMANAGER->printText(L"먹는다", dest3, 25);
	else if ((*_invItem)[_index]->getType() == ITEM_THROW) DTDMANAGER->printText(L"쏜다", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;

	DTDMANAGER->printText(L"건네준다", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;

	DTDMANAGER->printText(L"버린다", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"설명", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"돌아간다", dest3, 25);

	if (_hidden) _arrow->render(dest3.left - 20, (dest3.top - TILEHEIGHT * 3) + _index2 * 36);
}

void InvenMenu::printTextRight2()
{
	D2D1_RECT_F dest3 = dRectMake(_rc.left + _tuningX + TILEWIDTH * 9 + 25, _rc.top + _tuningY + 12,
		TILEWIDTH * 10, TILEHEIGHT);

	_back3->render(_rc.left + _tuningX, _rc.top + _tuningY, 0.5);
	_border3->render(_rc.left + _tuningX, _rc.top + _tuningY);	

	DTDMANAGER->printText(L"건네준다", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"버린다", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"설명", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"돌아간다", dest3, 25);

	if (_hidden) _arrow->render(dest3.left - 20, (dest3.top - 10 - TILEHEIGHT * 2) + _index2 * 36);
}

void InvenMenu::printTextDown()
{
	D2D1_RECT_F dest2 = dRectMake(_rc.left + _tuningX + TILEWIDTH / 2, _rc.top + _tuningY + TILEHEIGHT * 9,
		TILEWIDTH * 10, TILEHEIGHT);

	//아이템설명
	DTDMANAGER->printText((*_invItem)[_index]->getItemInfo().c_str(), dest2, 25);
}

void InvenMenu::plusIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		_index = (_index + 1) % _invItem->size();
	}

	if (_hidden)
	{
		if ((*_invItem)[_index]->getType() == ITEM_HOLD) _index2 = (_index2 + 1) % END_INVENMENU_GIVE_OPTION;
		else _index2 = (_index2 + 1) % END_INVENMENU_OPTION;
	}
	else _index2 = 0;
}

void InvenMenu::minusIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		_index = (_index - 1 + _invItem->size()) % _invItem->size();
	}

	if (_hidden)
	{
		if ((*_invItem)[_index]->getType() == ITEM_HOLD) _index2 = (_index2 - 1 + END_INVENMENU_GIVE_OPTION) % END_INVENMENU_GIVE_OPTION;
		else _index2 = (_index2 - 1 + END_INVENMENU_OPTION) % END_INVENMENU_OPTION;
	}
	else _index2 = 0;
}

void InvenMenu::leftIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		//_index = (_index - 7 + _invItem->size()) % _invItem->size();
		_index -= 7;

		if (_index < 0) _index = 0;
	}
}

void InvenMenu::rightIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		//_index = (_index + 7) % _invItem->size();
		_index += 7;

		if (_invItem->size() < _index) _index = 0;
	}
}
