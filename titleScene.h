#pragma once
#include "Scene.h"

class titleScene : public Scene
{
private:
	bool _change;

public:
	HRESULT init(Player* player);
	void release();
	void update();
	void render();

	void changeScene();
};

