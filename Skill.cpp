#include "stdafx.h"
#include "Skill.h"

HRESULT Skill::init(Player * player)
{
	_player = player;
	return S_OK;
}

void Skill::useSkill()		//플레이어 포인트를 받아와서		+	최종결정력 담을 변수			//자속은 bool값 or float값으로, 도구는 값으로
{
	//if (_currentPP <= 0) return;

	int direct = _player->getPokemon()->getDirect();

	_currentPP--;

	_x = _player->getX();
	_y = _player->getY();

	if ((direct & RIGHT) == RIGHT)
		_x++;
	else if ((direct & LEFT) == LEFT)
		_x--;

	if ((direct & DOWN) == DOWN)
		_y++;
	else if ((direct & UP) == UP)
		_y--;

	_finalDamage = BATTLEMANAGER->skillCalculation(_player, this);
}

/*
공or 특공->플레이어 공 / 특공 and 스킬의 공격타입 필요
스킬 자체데미지
자속->플레이어의 속성 and 스킬의 속성 필요



공격실능 or 특공실능 * 기술위력 * 자속 * 특성 * 도구 * 날씨
*/