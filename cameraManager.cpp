#include "stdafx.h"
#include "cameraManager.h"

cameraManager::cameraManager()
{
}

cameraManager::~cameraManager()
{
}

HRESULT cameraManager::init()
{
	//backDC�� frontDCũ�� ����
	_backWidth = WINSIZEX;
	_backHeight = WINSIZEY;
	_frontWidth = 5 * WINSIZEX / 8;
	_frontHeight = 5 * WINSIZEY / 8;

	//ȭ�� Rect ����
	_screen = dRectMake(0, 0, 5 * WINSIZEX / 8, 5 * WINSIZEY / 8);

	//fadeȭ��
	_fadeScreen = IMAGEMANAGER->addDImage("fade_B", L"img/fade_B.png", 5 * WINSIZEY / 8, 5 * WINSIZEY / 8);

	_alpha = 1.0;
	_fade = NORMAL;

	//������
	_count = 0;
	_ratioX = 0.5;
	_ratioY = 0.5;
	_camY = 0;
	_onMove = false;

	return S_OK;
}

void cameraManager::release()
{
}

void cameraManager::updateScreen(float standardX, float standardY)
{
	//�÷��̾� �������� ȭ��(_screen)����
	//playground.cpp�� update()���� ��� �������ָ� ��
	//�μ��� ������ �Ǵ� ��ü�� x, y��ǥ�� ����(����� player�� x, y)

	if (!_onMove)
		resetCam();

	float x = standardX * TILEWIDTH + TILEWIDTH / 2;
	float y = standardY * TILEHEIGHT + TILEHEIGHT / 2 + _camY;

	onWindow(x, y);
	//����
	_screen = dRectMake(x, y, _frontWidth, _frontHeight);
}

void cameraManager::moveCam(int direct)
{
	_onMove = true;

	switch (direct) {
	case 2:	//UP
		_camY = _camY - 10 > -240 ? _camY - 10 : -240;
		break;
	case 3:	//DOWN
		_camY = _camY + 10 < 240 ? _camY + 10 : 240;
		break;
	default:
		break;
	}
}

void cameraManager::resetCam()
{
	if (_camY > 0)
		_camY = _camY - 40 > 0 ? _camY - 40 : 0;
	else if (_camY < 0)
		_camY = _camY + 40 < 0 ? _camY + 40 : 0;
}

void cameraManager::fade()
{
	//���̵� �� �ƿ�
	if (_fade == FADEIN)		fadeIn();
	else if (_fade == FADEOUT)	fadeOut();
}

void cameraManager::fadeIn()
{
	_alpha -= FADE * TIMEMANAGER->getElapsedTime();
	if (_alpha < 0) _alpha = 0;

	if (_alpha == 0) _fade = NORMAL;

	D2D1_RECT_F dest = dRectMake(3 * WINSIZEX / 16, 3 * WINSIZEY / 8, _frontWidth, _frontHeight);
	D2D1_RECT_F sour = dRectMake(0, 0, _fadeScreen->getWidth(), _fadeScreen->getHeight());
	DTDMANAGER->getRenderTarget()->DrawBitmap(_fadeScreen->getBitmap(), dest,
		_alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);
}

void cameraManager::fadeOut()
{
	_alpha += FADE * TIMEMANAGER->getElapsedTime();
	if (_alpha > 1.0) _alpha = 1.0;

	if (_alpha == 1.0) _fade = NORMAL;

	D2D1_RECT_F dest = dRectMake(3 * WINSIZEX / 16, 3 * WINSIZEY / 8, _frontWidth, _frontHeight);
	D2D1_RECT_F sour = dRectMake(0, 0, _fadeScreen->getWidth(), _fadeScreen->getHeight());
	DTDMANAGER->getRenderTarget()->DrawBitmap(_fadeScreen->getBitmap(), dest,
		_alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);
}

void cameraManager::vibrateScreen(float standardX, float standardY, float magnitude, float interval)
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= interval) {
		updateScreen(standardX + RND->getFromFloatTo(-magnitude, magnitude),
			standardY + RND->getFromFloatTo(-magnitude, magnitude));
		_count = 0;
	}
}

void cameraManager::vibrateScreenOut(float standardX, float standardY, float magnitude, float interval)
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= interval) {
		float x = standardX;
		float y = standardY + _camY;

		onWindow(x, y);
		_screen = dRectMake(x + RND->getFromFloatTo(-magnitude, magnitude),
			y + RND->getFromFloatTo(-magnitude, magnitude),
			_frontWidth, _frontHeight);
		_count = 0;
	}
}

void cameraManager::render(float destX, float destY)
{
	/********* �μ� ���� *********/ /*
	int destX: �츮�� ���� ȭ�鿡�� ������� x��ǥ
	int destY: �츮�� ���� ȭ�鿡�� ������� y��ǥ
	*/

	DTDMANAGER->render(destX, destY, _frontWidth, _frontHeight);

#ifdef _DEBUG
#endif // _DEBUG

}

void cameraManager::onWindow(float & x, float & y)
{
	//X�� (��, ��)
	if (x - _frontWidth * _ratioX < 0)
		x = 0;
	else if (x + _frontWidth * (1 - _ratioX) > _backWidth)
		x = _backWidth - _frontWidth;
	else
		x -= _frontWidth * _ratioX;
	//Y�� (��, ��)
	if (y - _frontHeight * _ratioY < 0)
		y = 0;
	else if (y + _frontHeight * (1 - _ratioY) > _backHeight)
		y = _backHeight - _frontHeight;
	else
		y -= _frontHeight * _ratioY;
}

void cameraManager::setBackScreenSize(float width, float height)
{
	_backWidth = width, _backHeight = height;

	DTDMANAGER->setBackBuffer(width, height);
}