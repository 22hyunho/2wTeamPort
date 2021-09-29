#pragma once
#include "Player.h"
#include <vector>

class Pattern;
class Atile;

class Enemy : public Player
{
private:

public:
	virtual HRESULT init(int pokemonNum, int level);

	virtual	int input();
};

