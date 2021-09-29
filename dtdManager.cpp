#include "stdafx.h"
#include "dtdManager.h"

HRESULT dtdManager::init()
{
	release();

	_clear = true;

	HRESULT hr;

	//Fafctory ����
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_dFactory);

	//Factory�� �����Ǿ����� RenderTarget ����
	if (SUCCEEDED(hr)) {
		hr = _dFactory->CreateHwndRenderTarget(RenderTargetProperties(),
			HwndRenderTargetProperties(_hWnd, SizeU(WINSIZEX, WINSIZEY)),
			&_dRenderTarget);
	}

	//RenderTarget�� ȣȯ�Ǵ� �� �ٸ� RenderTarget(=BackBuffer) ����
	if (SUCCEEDED(hr)) {
		hr = _dRenderTarget->CreateCompatibleRenderTarget(SizeF(WINSIZEX, WINSIZEY),
			&_dBitRenderTarget);
	}

	//RenderTarget�� �����Ǿ����� Brush ����
	if (SUCCEEDED(hr)) {
		hr = _dRenderTarget->CreateSolidColorBrush(ColorF(ColorF::Black), &_dBrush);
	}

	//Brush�� �����Ǿ����� Text Factory ����
	if (SUCCEEDED(hr)) {
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&_dWFactory)
		);
	}

	//Text Factory�� �����Ǿ����� Text Format ����
	if (SUCCEEDED(hr)) {
		hr = _dWFactory->CreateTextFormat(
			L"�𸮽�9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			15,
			L"ko-kr",
			&_dWDefaultFormat
		);
	}

	//Text Format�� �����Ǿ����� Text Brush ����
	if (SUCCEEDED(hr)) {
		hr = _dRenderTarget->CreateSolidColorBrush(ColorF(ColorF::White), &_tBrush);
	}

	//Text Format�� �����Ǿ����� �⺻��(��� ����) ����
	/*if (SUCCEEDED(hr)) {
		hr = _dWFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

		if (SUCCEEDED(hr)) {
			hr = _dWFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
		}
	}*/

	//wincodec(�̹��� �δ�)�� ����ϱ� ����
	CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

	return S_OK;
}

void dtdManager::release()
{
	//���� �Ҵ��� ��ü�� ��� ����
	if (_dFactory)			SAFE_RELEASE2(_dFactory);
	if (_dRenderTarget)		SAFE_RELEASE2(_dRenderTarget);
	if (_dBitRenderTarget)	SAFE_RELEASE2(_dBitRenderTarget);
	if (_dBitmap)			SAFE_RELEASE2(_dBitmap);
	if (_dBrush)			SAFE_RELEASE2(_dBrush);

	if (_dWFactory)			SAFE_RELEASE2(_dWFactory);
	if (_dWDefaultFormat)	SAFE_RELEASE2(_dWDefaultFormat);
	if (_dWCustomFormat)	SAFE_RELEASE2(_dWCustomFormat);
	if (_tBrush)			SAFE_RELEASE2(_tBrush);
}

void dtdManager::render(float destX, float destY, float width, float height)
{
	if (!_dRenderTarget) return;

	_dRenderTarget->BeginDraw();
	_dRenderTarget->Clear(ColorF(ColorF::Aquamarine));

	//�� ȭ��
	UIMANAGER->renderUp();

	//�Ʒ� ȭ�� (���� ���� ȭ��)
	D2D1_RECT_F dest = { destX, destY, destX + width, destY + height };
	D2D1_RECT_F sour = CAMERAMANAGER->getScreen();

	_dRenderTarget->DrawBitmap(_dBitmap, dest,
		1.0, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);

	CAMERAMANAGER->fade();

	_dRenderTarget->EndDraw();
}

void dtdManager::beginDraw()
{
	if (_dBitRenderTarget) {
		_dBitRenderTarget->BeginDraw();
		_dBitRenderTarget->Clear();
	}
}

void dtdManager::endDraw()
{
	if (_dBitRenderTarget) {
		//SAFE_RELEASE2(_dBitmap);
		_dBitRenderTarget->GetBitmap(&_dBitmap);

		_dBitRenderTarget->EndDraw();
	}
}

void dtdManager::Rectangle(D2D1_RECT_F rc)
{
	if (_dBitRenderTarget)
		_dBitRenderTarget->DrawRectangle(rc, _dBrush);
}

void dtdManager::Rectangle(RECT rc)
{
	D2D1_RECT_F rect = { rc.left, rc.top, rc.right, rc.bottom };

	if (_dBitRenderTarget)
		_dBitRenderTarget->DrawRectangle(rect, _dBrush);
}

void dtdManager::printTextF(LPCWCHAR text, float x, float y, int width, int height)
{
	_dRenderTarget->DrawTextA(text, lstrlenW(text), _dWDefaultFormat, dRectMakeCenter(x, y, width, height), _tBrush);
}

void dtdManager::printTextF(LPCWCHAR text, float x, float y, int width, int height, float size)
{
	if (_dWCustomFormat) {
		if (_dWCustomFormat->GetFontSize() != size) {
			SAFE_RELEASE2(_dWCustomFormat);

			_dWFactory->CreateTextFormat(
				L"�𸮽�9",
				nullptr,
				DWRITE_FONT_WEIGHT_NORMAL,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"ko-kr",
				&_dWCustomFormat
			);
		}
	}
	else {
		_dWFactory->CreateTextFormat(
			L"�𸮽�9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			size,
			L"ko-kr",
			&_dWCustomFormat
		);
	}

	_dRenderTarget->DrawTextA(text, lstrlenW(text), _dWCustomFormat, dRectMakeCenter(x, y, width, height), _tBrush);
}

void dtdManager::printTextF(LPCWCHAR text, D2D1_RECT_F rc)
{
	_dRenderTarget->DrawTextA(text, lstrlenW(text), _dWDefaultFormat, rc, _tBrush);
}

void dtdManager::printTextF(LPCWCHAR text, D2D1_RECT_F rc, float size)
{
	if (_dWCustomFormat) {
		if (_dWCustomFormat->GetFontSize() != size) {
			SAFE_RELEASE2(_dWCustomFormat);

			_dWFactory->CreateTextFormat(
				L"�𸮽�9",
				nullptr,
				DWRITE_FONT_WEIGHT_NORMAL,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"ko-kr",
				&_dWCustomFormat
			);
		}
	}
	else {
		_dWFactory->CreateTextFormat(
			L"�𸮽�9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			size,
			L"ko-kr",
			&_dWCustomFormat
		);
	}

	_dRenderTarget->DrawTextA(text, lstrlenW(text), _dWCustomFormat, rc, _tBrush);
}

void dtdManager::printText(LPCWCHAR text, float x, float y, int width, int height)
{
	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWDefaultFormat, dRectMakeCenter(x, y, width, height), _tBrush);
}

void dtdManager::printText(LPCWCHAR text, float x, float y, int width, int height, float size, bool central)
{
	if (_dWCustomFormat) {
		if (_dWCustomFormat->GetFontSize() != size) {
			SAFE_RELEASE2(_dWCustomFormat);

			_dWFactory->CreateTextFormat(
				L"�𸮽�9",
				nullptr,
				DWRITE_FONT_WEIGHT_NORMAL,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"ko-kr",
				&_dWCustomFormat
			);
		}
	}
	else {
		_dWFactory->CreateTextFormat(
			L"�𸮽�9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			size,
			L"ko-kr",
			&_dWCustomFormat
		);
	}

	if (central) {
		_dWCustomFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		_dWCustomFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	}

	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWCustomFormat, dRectMakeCenter(x, y, width, height), _tBrush);

	SAFE_RELEASE2(_dWCustomFormat);
}

void dtdManager::printText(LPCWCHAR text, D2D1_RECT_F rc)
{
	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWDefaultFormat, rc, _tBrush);
}

void dtdManager::printText(LPCWCHAR text, D2D1_RECT_F rc, float size, bool central)
{
	if (_dWCustomFormat) {
		if (_dWCustomFormat->GetFontSize() != size) {
			SAFE_RELEASE2(_dWCustomFormat);

			_dWFactory->CreateTextFormat(
				L"�𸮽�9",
				nullptr,
				DWRITE_FONT_WEIGHT_NORMAL,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"ko-kr",
				&_dWCustomFormat
			);
		}
	}
	else {
		_dWFactory->CreateTextFormat(
			L"�𸮽�9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			size,
			L"ko-kr",
			&_dWCustomFormat
		);
	}
	
	if (central) {
		_dWCustomFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		_dWCustomFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	}

	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWCustomFormat, rc, _tBrush);

	SAFE_RELEASE2(_dWCustomFormat);
}

void dtdManager::setRotate(float angle, float x, float y)
{
	_dBitRenderTarget->SetTransform(Matrix3x2F::Rotation(angle, Point2F(x, y)));
}

void dtdManager::setReverse(int axis, float offsetX, float offsetY)
{
	//axis == 0 y�� (�¿� ����)
	//axis == 1 x�� (���� ����)

	D2D1_MATRIX_3X2_F m;

	if (axis == 0) {
		m._11 = -1; m._12 = 0;
		m._21 = 0; m._22 = 1;
	}
	else if (axis == 1) {
		m._11 = 1; m._12 = 0;
		m._21 = 0; m._22 = -1;
	}
	m._31 = offsetX; m._32 = offsetY;

	_dBitRenderTarget->SetTransform(m);
}

void dtdManager::setScale(float sizeX, float sizeY, float x, float y)
{
	_dBitRenderTarget->SetTransform(Matrix3x2F::Scale(SizeF(sizeX, sizeY), Point2F(x, y)));
}

void dtdManager::resetTransform()
{
	_dBitRenderTarget->SetTransform(Matrix3x2F::Identity());
}

void dtdManager::setBackBuffer(float width, float height)
{
	SAFE_RELEASE2(_dBitRenderTarget);

	if (_dRenderTarget) {
		_dRenderTarget->CreateCompatibleRenderTarget(SizeF(width, height), &_dBitRenderTarget);
	}
}

void dtdManager::resetBrushColor()
{
	_dBrush->SetColor(ColorF(ColorF::Black));
}