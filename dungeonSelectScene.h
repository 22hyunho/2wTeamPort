#pragma once
#include "Scene.h"
class dungeonSelectScene:public Scene
{
private:
	dImage* _background;
	int _width;
	int _height;
	int _x;
	int _y;
	int _type;

	RECT _selector;
	RECT _d0;
	RECT _d1;
	RECT _d2;
	RECT _d3;
	RECT _d4;
	RECT _d5;
	RECT _d6;
	RECT _d7;

	bool _change;

public:
	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

