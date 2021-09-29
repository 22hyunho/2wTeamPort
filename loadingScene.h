#pragma once
#include "Scene.h"

#define LOADINGMAX	10.0f

class loadingScene : public Scene
{
private:
	dImage* _back;

public:

	float _currentCount;
	bool _create;

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();

	static DWORD CALLBACK threadFunction(LPVOID lpParameter);
};

