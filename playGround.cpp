#include "stdafx.h"
#include "playGround.h"
#include "User.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);

	_player = new User;

	SCENEMANAGER->init(_player);

	SCENEMANAGER->changeScene("title");

	BATTLEMANAGER->init();
	DIALOGMANAGER->init();

	_debug = false;

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();

	BATTLEMANAGER->release();
	BATTLEMANAGER->releaseSingleton();

	DIALOGMANAGER->release();
	DIALOGMANAGER->releaseSingleton();
}


void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		_debug = !_debug;
		PRINTMANAGER->setDebug(_debug);
	}

	SCENEMANAGER->update();
	SOUNDMANAGER->update();
}


void playGround::render()
{
	if (STREAMMANAGER->getCurrentVideo()) {
		if (STREAMMANAGER->getPosition() < STREAMMANAGER->getLength())
			return;
	}

	DTDMANAGER->beginDraw();
	//================제발 이 사이에 좀 그립시다==========================
	SCENEMANAGER->render();

	DTDMANAGER->endDraw();
	//==================================================================
	CAMERAMANAGER->render(3 * WINSIZEX / 16, 3 * WINSIZEY / 8);
}