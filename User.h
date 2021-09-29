#pragma once
#include "Player.h"

class User : public Player
{
private:
	int _num;

public:
	virtual HRESULT init(int pokemonNum, int level);

	virtual	int input();

	void controlKey();
	void testKey();
};