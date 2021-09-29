#pragma once
#include "Scene.h"

class resultScene :	public Scene
{
private:
	dImage* _back;

public:
	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

