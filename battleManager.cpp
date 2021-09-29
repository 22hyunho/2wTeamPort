#include "stdafx.h"
#include "battleManager.h"
#include "Item.h"

battleManager::battleManager() :
	_counter{
/*			노말	격투	독	땅	비행	벌레	바위	고스	강철	불	물	전기	풀	얼음	에스	드래	악			*/
		{	C,	C,	C,	C,	C,	C,	W,	N,	W,	C,	C,	C,	C,	C,	C,	C,	C	},	//노말
		{	G,	C,	W,	C,	W,	W,	G,	N,	G,	C,	C,	C,	C,	G,	W,	C,	G	},  //격투
		{	C,	C,	W,	W,	C,	C,	W,	W,	N,	C,	C,	C,	G,	C,	C,	C,	C	},  //독
		{	C,	C,	G,	C,	N,	W,	G,	C,	G,	G,	C,	G,	W,	C,	C,	C,	C	},  //땅
		{	C,	G,	C,	C,	C,	G,	W,	C,	W,	C,	C,	W,	G,	C,	C,	C,	C	},  //비행
		{	C,	W,	W,	C,	W,	C,	C,	W,	W,	W,	C,	C,	G,	C,	G,	C,	G	},  //벌레
		{	C,	W,	C,	W,	G,	G,	C,	C,	W,	G,	C,	C,	C,	G,	C,	C,	C	},  //바위
		{	N,	C,	C,	C,	C,	C,	C,	G,	C,	C,	C,	C,	C,	C,	G,	C,	W	},  //고스트
		{	C,	C,	C,	C,	C,	C,	G,	C,	W,	W,	W,	W,	C,	G,	C,	C,	C	},  //강철
		{	C,	C,	C,	C,	C,	G,	W,	C,	G,	W,	W,	C,	G,	G,	C,	W,	C	},  //불
		{	C,	C,	C,	G,	C,	C,	G,	C,	C,	G,	W,	C,	W,	C,	C,	W,	C	},  //물
		{	C,	C,	C,	N,	G,	C,	C,	C,	C,	C,	G,	W,	W,	C,	C,	W,	C	},  //전기
		{	C,	C,	W,	G,	W,	W,	G,	C,	W,	W,	G,	C,	W,	C,	C,	W,	C	},  //풀
		{	C,	C,	C,	G,	G,	C,	C,	C,	W,	W,	W,	C,	G,	W,	C,	G,	C	},  //얼음
		{	C,	G,	G,	C,	C,	C,	C,	C,	W,	C,	C,	C,	C,	C,	W,	C,	N	},  //에스퍼
		{	C,	C,	C,	C,	C,	C,	C,	C,	W,	C,	C,	C,	C,	C,	C,	G,	C	},  //드래곤
		{	C,	W,	C,	C,	C,	C,	C,	G,	C,	C,	C,	C,	C,	C,	G,	C,	W	},  //악
	}
{
}

battleManager::~battleManager()
{
}

HRESULT battleManager::init()
{

	return S_OK;
}

void battleManager::release()
{
}

void battleManager::update()
{
}

void battleManager::render()
{
}

int battleManager::EXPCalculation(Player * player)
{
	STAT stat = player->getPokemon()->getPokemonValue();

	int sum = stat.hp + stat.attack + stat.defense + stat.sattack + stat.sdefense + stat.speed;

	return sum * (player->getLevel() / (float)100) * 3;
	//return 30000;
}

STAT battleManager::statCalculation(Player * player)
{
	//종족값, 레벨
	STAT baseStat = player->getPokemon()->getPokemonValue();
	int level = player->getLevel();
	//실능력치
	STAT realStat;

	realStat.hp = STAT_CALCULATION(baseStat.hp, level);
	realStat.attack = STAT_CALCULATION(baseStat.attack, level);
	realStat.defense = STAT_CALCULATION(baseStat.defense, level);
	realStat.sattack = STAT_CALCULATION(baseStat.sattack, level);
	realStat.sdefense = STAT_CALCULATION(baseStat.sdefense, level);
	realStat.speed = STAT_CALCULATION(baseStat.speed, level);

	return realStat;
}

float battleManager::skillCalculation(Player * player, Skill * skill)
{
	int atkType;
	float stab = 1.0f;
	float equip;

	//포켓몬 실능(물공 || 특공)
	if (skill->getAtkType() == PHYSICAL_ATTACK)	atkType = player->getRealStat().attack;
	else										atkType = player->getRealStat().sattack;

	//자속 여부 확인
	POKEMON_TYPE* playerType = player->getPokemon()->getPokemonType();
	POKEMON_TYPE  skillType = skill->getSkillType();
	if(skillType == END_POKEMON_TYPE) {}
	else if (playerType[0] == skillType || playerType[1] == skillType)	stab = 1.5f;

	//도구 확인
	//if(player->getItem())
	//	equip = player->getItem()->
	//일단은 1


	//결정력계산
	float finalDamage = SKILL_CALCULATION(atkType, skill->getDamage(), stab, 1, 1, 1);

	//enemy가 쓴 스킬은 음수, team이 쓴 스킬은 양수
	if (player->getPlayerType() == PLAYER_TYPE_ENEMY)	return -finalDamage;
	else											    return finalDamage;
}

float battleManager::defenceCalculation(Player * player, Effect * effect)
{
	int defType;

	if (effect->getAtkType() == PHYSICAL_ATTACK) defType = player->getRealStat().defense;
	else										 defType = player->getRealStat().sdefense;

	return DEFENCE_CALCULATION(player->getRealStat().hp, defType);
}

float battleManager::damageCalculation(Player * player, Effect * effect)
{
	// 총 데미지 계산식
	// 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)
	int skillDamage;
	int defense;

	skillDamage = effect->getDamage();
	defense = defenceCalculation(player, effect);

	//상성
	float counter = 1.0f;
	POKEMON_TYPE*	playerType = player->getPokemon()->getPokemonType();
	POKEMON_TYPE	skillType = effect->getType();

	if (playerType[0] < END_POKEMON_TYPE && skillType < END_POKEMON_TYPE)
		counter *= _counter[skillType][playerType[0]];
	if (playerType[1] < END_POKEMON_TYPE && skillType < END_POKEMON_TYPE)
		counter *= _counter[skillType][playerType[1]];

	

	float finalDamage = (float)skillDamage / defense * RND->getFromIntTo(35, 50) * counter;
	
	//최소 데미지 1
	if (0 < finalDamage && finalDamage < 1)
		finalDamage = 1;
	else if (-1 < finalDamage && finalDamage < 0)
		finalDamage = -1;
	
	//로그 추가
	DIALOGMANAGER->hitDamageLog(player, abs(finalDamage));
	if (counter >= 2)
		DIALOGMANAGER->greatSkillLog();
	else if (0 < counter && counter <= 0.5)
		DIALOGMANAGER->worseSkillLog();
	else if (counter <= 0)
		DIALOGMANAGER->noneSkillLog();

	return finalDamage;
}



//최종 데미지용 함수 추가


//내구력 공식 : HP 실능 x 방 or 특방 실능 / 0.411
//데미지 공식 : 스킬공격력 / 내구력 * 랜덤수(85~100)


//총정리
//스킬공격력 : 공격자 공 or 특공 실능 * 사용한 기술 위력 * 사용한 기술 자속여부 * 특성 * 도구 * 날씨
//내구력		: 방어자 HP 실능 * 방어자 방 or 특방 실능 / 0.411f
//총데미지	: 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)