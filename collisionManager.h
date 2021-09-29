#pragma once
#include "singletonBase.h"
#include "tileInfo.h"
#include <vector>

class Player;
class Scene;
class Item;
class Effect;

class collisionManager : public singletonBase<collisionManager>
{
private:
	Scene* _scene;
	vector<tagTile*>* _allTile;		//타일 목록
	vector<Item*>* _allItem;		//아이템 목록
	vector<Player*>* _allPlayer;	//플레이어 목록

	//충돌하는 객체들 파악하기
	//플레이어랑 에너미
	//플레이어랑 아이템

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Scene* scene);
	void release();

	//Player 충돌(입력 턴)
	bool collisionInputPlayer(Player* player);
	bool playerWithTile(Player* player);
	bool playerWithPlayer(Player* player);
	
	//Player 충돌(엔드 턴)
	void collisionEndTurnPlayer(Player* player);
	void playerWithItem(Player* player);
	void playerWithObject(Player* player);

	//감지범위 충돌
	void collisionDetection(Player* player);
	bool detectionWithRoom(Player* startPlayer, Player* destPlayer);
	bool detectionWith8Tiles(Player* startPlayer, Player* destPlayer);

	//이펙트 충돌
	void effectWithEnemy(Effect* effect);
};
