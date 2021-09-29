#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/0.png", 544, ITEMSIZE, 17, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);

	_gummyNum = RND->getInt(END_POKEMON_TYPE);

	_itemInfo = L"지능이 올라간다";
	_type = ITEM_FOOD;

	switch (_gummyNum)
	{
	case 0:
		_name = L"빨간구미";
		_gummyType = POKEMON_TYPE_FIRE;

		_num = 2;

		break;

	case 1:
		_name = L"주황구미";
		_gummyType = POKEMON_TYPE_FIGHTING;

		_num = 3;

		break;

	case 2:
		_name = L"노란구미";
		_gummyType = POKEMON_TYPE_ELECTRIC;

		_num = 4;

		break;

	case 3:
		_name = L"새싹구미";
		_gummyType = POKEMON_TYPE_GRASS;

		_num = 5;

		break;

	case 4:
		_name = L"초록구미";
		_gummyType = POKEMON_TYPE_BUG;

		_num = 6;

		break;

	case 5:
		_name = L"하늘색구미";
		_gummyType = POKEMON_TYPE_FLYING;

		_num = 7;

		break;

	case 6:
		_name = L"파란구미";
		_gummyType = POKEMON_TYPE_WATER;

		_num = 8;

		break;

	case 7:
		_name = L"감색구미";
		_gummyType = POKEMON_TYPE_DRAGON;

		_num = 9;

		break;

	case 8:
		_name = L"보라구미";
		_gummyType = POKEMON_TYPE_GHOST;

		_num = 10;

		break;

	case 9:
		_name = L"분홍구미";
		_gummyType = POKEMON_TYPE_POISON;

		_num = 11;

		break;

	case 10:
		_name = L"검정구미";
		_gummyType = POKEMON_TYPE_DARK;

		_num = 12;

		break;

	case 11:
		_name = L"갈색구미";
		_gummyType = POKEMON_TYPE_GROUND;

		_num = 13;

		break;

	case 12:
		_name = L"하얀구미";
		_gummyType = POKEMON_TYPE_NORMAL;
		_itemInfoLong = L"먹으면 배고픔이 약간 회복된다\n 탐험대의 동료에게 주면\n 지능이 올라간다\n 노말타입 포켓몬이\n 좋아하는 음식이다\n 던전 안에서 먹는것이\n 조금 더 유리하다!";

		_num = 14;

		break;

	case 13:
		_name = L"은색구미";
		_gummyType = POKEMON_TYPE_STEEL;

		_num = 15;

		break;

	case 14:
		_name = L"회색구미";
		_gummyType = POKEMON_TYPE_ROCK;

		_num = 16;

		break;

	case 15:
		_name = L"투명(255.0.255)구미";
		_gummyType = POKEMON_TYPE_ICE;

		_num = 17;

		break;

	case 16:
		_name = L"금색구미";
		_gummyType = POKEMON_TYPE_PSYCHIC;

		_num = 18;

		break;
	}

	return S_OK;
}

void Gummy::release()
{
}

void Gummy::update()
{
}

void Gummy::render()
{
	if (PRINTMANAGER->isDebug())	DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x * TILEWIDTH + TILEWIDTH / 2 - _img->getFrameWidth() / 2,
	_y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getFrameHeight() / 2, _gummyNum, 0);
}