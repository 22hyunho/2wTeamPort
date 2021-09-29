#include "stdafx.h"
#include "EffectManager.h"

HRESULT EffectManager::init()
{
	//registerEffect(EF_FIREBLAST, new EF_FireBlast);
	//registerEffect(EF_GUST, new EF_Gust);
	//registerEffect(EF_LIGHTNING, new EF_Lightning);
	//registerEffect(EF_ROCKSLIDE, new EF_RockSlide);
	return S_OK;
}

void EffectManager::release()
{
}

void EffectManager::update()
{
	for (_viEffect = _vEffect.begin(); _viEffect != _vEffect.end();)
	{
		if ((*_viEffect)->getOff())
		{
			// 에러나면 순서만 바꾸기	//이거 활성화시키니 새로 이펙트가 나오면 터짐
			SAFE_DELETE(*_viEffect);
			_viEffect = _vEffect.erase(_viEffect);
		}
		else ++_viEffect;
	}
}

void EffectManager::render()
{
	for (_viEffect = _vEffect.begin(); _viEffect != _vEffect.end(); ++_viEffect)
	{
		(*_viEffect)->render();
	}
}

/*Effect * EffectManager::registerEffect(int effectNum, Effect * effect)
{
	if (!effect) return nullptr;

	_mEffectList.insert(make_pair(effectNum, effect));

	return effect;
}*/

void EffectManager::addEffect(Effect* effect)
{
	_vEffect.push_back(effect);
}
