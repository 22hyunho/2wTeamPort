#include "stdafx.h"
#include "Effect.h"

HRESULT Effect::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);
	_count = 0;
	_off = false;

	_scale = skillScale; // 타격범위로
	_damage = damage;
	_atkType = atkType;
	_type = type;

	return S_OK;
}

void Effect::render()
{
	_img->frameRender(_x * TILEWIDTH + TILEWIDTH / 2 + _tuningX,
		_y *TILEHEIGHT + TILEHEIGHT / 2 + _tuningY);
	//DTDMANAGER->Rectangle(_body);
	controlFrame();
}

void Effect::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= _renderCount)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			COLLISIONMANAGER->effectWithEnemy(this);
			TURNMANAGER->getCurrentPlayer()->getPokemon()->setAttack(false);
			TURNMANAGER->getCurrentPlayer()->getPokemon()->setSattack(false);
			_off = true;
		}
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
