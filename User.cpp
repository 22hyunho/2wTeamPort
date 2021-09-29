#include "stdafx.h"
#include "User.h"

HRESULT User::init(int pokemonNum, int level)
{
	Player::init(pokemonNum, level);

	//�÷��̾� Ÿ��
	_playerType = PLAYER_TYPE_USER;
	_playerState = END_POKEMON_STATE;
	//���� ����
	for (int i = 0; i < END_PLAYER_PATTERN; i++)
		_pattern[i] = nullptr;
	_currentPattern = END_PLAYER_PATTERN;

	//���
	_selectedSkill = nullptr;
	_default = SKILLDEX->makeSkill(0);
	_default->init(this);

	_num = POKEDEX->getIndex();

	return S_OK;
}

int User::input()
{
	//ü�� �� �����
	if (_turnCount >= 5) {
		if (_currentHP < _realStat.hp)
			_currentHP++;

		_starve--;
		if (_starve <= 0)
			_starve = 0;

		_turnCount = 0;
	}

	controlKey();
	//testKey();

	return _playerState;
}

void User::controlKey()
{
	_direct = 0;

	//������ȯ
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT)) {
		_direct |= RIGHT;
		_pokemon->changeDirect(_direct);
	}
	else if (KEYMANAGER->isStayKeyDown(KEY_LEFT)) {
		_direct |= LEFT;
		_pokemon->changeDirect(_direct);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP)) {
		_direct |= UP;
		_pokemon->changeDirect(_direct);
	}
	else if (KEYMANAGER->isStayKeyDown(KEY_DOWN)) {
		_direct |= DOWN;
		_pokemon->changeDirect(_direct);
	}

	//���� �Է��� ���� �� (_direct != 0)
	if (!KEYMANAGER->isStayKeyDown(KEY_L1)) {
		if (_direct && COLLISIONMANAGER->collisionInputPlayer(this))
		{
			if ((_direct & RIGHT) == RIGHT) _destX++;
			else if ((_direct & LEFT) == LEFT) _destX--;

			if ((_direct & UP) == UP) _destY--;
			else if ((_direct & DOWN) == DOWN) _destY++;

			_playerState = POKEMON_STATE_MOVE;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A))
		useSkill(-1);
	if (KEYMANAGER->isOnceKeyDown('F')) levelUP();

	if (KEYMANAGER->isOnceKeyDown(KEY_Y)) {
		SOUNDMANAGER->play("Option");
		UIMANAGER->changeDownMenu("mainMenu");
		UIMANAGER->setOpen(true);
	}
}

void User::testKey()
{
	if (KEYMANAGER->isOnceKeyDown('1')) {
		if (_num >= POKEDEX->getIndex()) return;

		SAFE_DELETE(_pokemon);
		_num++;
		_pokemon = POKEDEX->makePokemon(_num);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('2')) {
		if (_num <= 1)	return;

		SAFE_DELETE(_pokemon);
		_num--;
		_pokemon = POKEDEX->makePokemon(_num);
		_pokemon->init();
	}
}