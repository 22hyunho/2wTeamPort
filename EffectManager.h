#pragma once
#include "Effect.h"
#include <vector>
#include <map>
#include "singletonBase.h"

class EffectManager : public singletonBase<EffectManager>
{
private:
	//typedef map<int, Effect*>				effectList;
	//typedef map<int, Effect*>::iterator		effectIter;

	typedef vector<Effect*>					skillEffect;
	typedef vector<Effect*>::iterator		skillIter;

private:
	//effectList	_mEffectList;
	//effectIter	_miEffectList;

	skillEffect	_vEffect;
	skillIter	_viEffect;

public:
	EffectManager() {};
	~EffectManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//Effect* registerEffect(int effectNum, Effect* effect);
	void addEffect(Effect* effect);
};