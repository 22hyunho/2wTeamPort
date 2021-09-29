#pragma once
#include "Scene.h"
#include "ItemManager.h"

class bossMapScene:public Scene
{
private:
	Player* _pokemon1;

	dImage* _background;


	int _width;
	int _height;
	int _type;

public:

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

