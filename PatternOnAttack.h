#pragma once
#include "Pattern.h"
#include "PathFinder.h"

class Atile;

class PatternOnAttack : public Pattern
{
private:
	PathFinder* _pathFinder;
	vector<Atile*> _pathList;

public:
	virtual HRESULT init(Player *player);
	virtual void release();
	virtual void update();
	virtual void render();

	void detour();

	vector<Atile*> getPathList() { return _pathList; }
};

