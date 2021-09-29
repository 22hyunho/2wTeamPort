#pragma once
#include "singletonBase.h"
#include "PokemonType.h"

#define G	2.0f	//GREAT		== 효과가 좋다
#define C	1.0f	//COMMON	== 일반
#define W	0.5f	//WORSE		== 효과가 별로
#define N	0.0f	//NONE		== 효과가 없다

// 계산식
// ( (종족값x2 + 개체값 + 노력치/4) x 레벨/100 + 10 + 레벨 ) x 성격보정
// 개체값은 28로 통일, 노력치는 0으로 통일, 성격은 없음
#define STAT_CALCULATION(baseStat, level)\
	((baseStat) * 2 + 28) * ((float)(level) / 100) + 10 + (level);

// 스킬 계산식
// 공격실능 or 특공실능 * 기술위력 * 자속 * 특성 * 도구 * 날씨		
// 특성, 날씨는 현재 1로고정
#define SKILL_CALCULATION(atkType, skillPower, stab, equip)\
	atkType * skillPower * stab * equip * 1 * 1;

// 내구력 계산식
// HP실능 * 방어실능 or 특방실능 / 0.411
#define DEFENCE_CALCULATION(realHP, defType)\
	realHP * defType / 0.411f;

// 총 데미지 계산식
// 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)

class Player;
class Effect;
class Item;

class battleManager : public singletonBase<battleManager>
{
private:
	float _counter[END_POKEMON_TYPE][END_POKEMON_TYPE];
	int _test[5][5];

public:
	battleManager();
	~battleManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//경험치 계산
	int EXPCalculation(Player* player);

	//실능력치 계산
	STAT statCalculation(Player* player);

	//결정력 계산
	float skillCalculation(Player* player, Skill* skill);
	//내구력 계산
	float defenceCalculation(Player* player, Effect* effect);
	//최종데미지 계산
	float damageCalculation(Player* player, Effect* effect);
};

