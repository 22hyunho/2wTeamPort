#pragma once
#include "Scene.h"

class mainScene : public Scene
{
private:
	dImage* _currentImage;

public:
	HRESULT init(Player* player);
	void release();
	void update();
	void render();

	void changeScene();
};

