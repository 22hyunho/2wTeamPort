#pragma once
#include "Player.h"

class Team : public Player
{
public:
	virtual HRESULT init(int pokemonNum, int level);

	virtual	int input();
};

