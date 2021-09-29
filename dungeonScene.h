#pragma once
#include "Scene.h"

class dungeonScene : public Scene
{
private:
	Player* _pokemon1;
	Player* _pokemon2;
	Player* _pokemon3;

public:

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

