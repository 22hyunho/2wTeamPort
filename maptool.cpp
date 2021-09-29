#include "stdafx.h"
#include "maptool.h"

Maptool::Maptool()
{
}

Maptool::~Maptool()
{
}

HRESULT Maptool::init()
{
	_maptile[0] = IMAGEMANAGER->addFrameDImage("terrain0", L"img/map/tiles/terrain_0.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[1] = IMAGEMANAGER->addFrameDImage("terrain1", L"img/map/tiles/terrain_1.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[2] = IMAGEMANAGER->addFrameDImage("terrain2", L"img/map/tiles/terrain_2.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[3] = IMAGEMANAGER->addFrameDImage("terrain3", L"img/map/tiles/terrain_3.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[4] = IMAGEMANAGER->addFrameDImage("terrain4", L"img/map/tiles/terrain_4.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[5] = IMAGEMANAGER->addFrameDImage("terrain5", L"img/map/tiles/terrain_5.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[6] = IMAGEMANAGER->addFrameDImage("terrain6", L"img/map/tiles/terrain_6.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_maptile[7] = IMAGEMANAGER->addFrameDImage("terrain7", L"img/map/tiles/terrain_7.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_object     = IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object_all.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_width = TILEMANAGER->getWidth();
	_height = TILEMANAGER->getHeight();
	setup();
	setSample();
	
	type = 0;
	mode = true;

	return S_OK;
}

void Maptool::release()
{
}

void Maptool::update()
{
	if (KEYMANAGER->isOnceKeyDown('1'))type--;
	if (KEYMANAGER->isOnceKeyDown('2'))type++;
	if (KEYMANAGER->isOnceKeyDown('3')) 
	{ 
		if(mode)mode=false;
		else if (!mode)mode = true;
	}
	if (KEYMANAGER->isOnceKeyDown('4')) { save("samplemap.map");}
	if (KEYMANAGER->isOnceKeyDown('5')) { load("samplemap.map");}
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON)) { _ctrSelect = CTRL_ERASER; setMap(); }
	if (KEYMANAGER->isStayKeyDown(VK_MBUTTON)) { _ctrSelect = CTRL_END; setMap(); }
if (PRINTMANAGER->isDebug())
{
	if (mode&& KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { _ctrSelect = CTRL_TERRAINDRAW; setMap(); }
	if (!mode && KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { _ctrSelect = CTRL_OBJDRAW; setMap(); }
}
	if (mode&& KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { setMap(); }
	if (!mode && KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { setMap(); }
	
	if (type < 0)type = 0;
	if (type >=8 )type = 7;
	setSample();
	
}

void Maptool::render()
{
	
	D2D1_RECT_F _rc =CAMERAMANAGER->getScreen();
	RECT rc;
	rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 5, 5);
	for (int i = 0; i < _width * _height; ++i)
	{
	_maptile[type]->frameRender(
			_vTile[i]->rc.left, _vTile[i]->rc.top,
			_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
	}
	for (int i = 0; i < _width * _height; ++i)
	{
		if (_vTile[i]->obj == OBJ_NONE) continue;

		_object->frameRender(
			_vTile[i]->rc.left, _vTile[i]->rc.top,
			_vTile[i]->objFrameX, _vTile[i]->objFrameY);
	}
	if (PRINTMANAGER->isDebug())
	{
		if (mode)
		{
			_maptile[type]->render(_rc.right - IMAGEMANAGER->findDImage("object")->getWidth(), _rc.top);
		}
		else if (!mode)
		{
			_object->render(_rc.right - IMAGEMANAGER->findDImage("object")->getWidth(), _rc.top);
		}
	}
	DTDMANAGER->Rectangle(rc);
	
}

void Maptool::save(const char * mapName)
{
	HANDLE file;
	DWORD write;

	file = CreateFile(mapName, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile)*_width*_height, &write, NULL);
	CloseHandle(file);
}

void Maptool::load(const char * mapName)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(mapName, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * _width * _height, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) *  _width * _height);
	_vTile.clear();
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			PTILE Tile;
			Tile = new TILE;
			SetRect(&Tile->rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
			_vTile.push_back(Tile);
		}
	}

	for (int i = 0; i < _width*_height; ++i)
	{
		_vTile[i]->terrainFrameX= _tiles[i].terrainFrameX;
		_vTile[i]->terrainFrameY= _tiles[i].terrainFrameY;
		_vTile[i]->objFrameX=_tiles[i].objFrameX;
		_vTile[i]->objFrameY=_tiles[i].objFrameY;
		_vTile[i]->terrain=_tiles[i].terrain;
		_vTile[i]->obj=_tiles[i].obj;
	}
	//STEP 01
	//타일을 불러온 다음 타일이 어떤 지형인지 오브젝트인지 분별해서
	//해당 타일에 속성을 부여해줍니다

	//for (int i = 0; i < _width * _height; ++i)
	//{
	//	if (_tiles[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK2) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK4) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK5) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK6) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK7) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK8) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_WATER) _attribute[i] |= ATTR_WATER;
	//}



	CloseHandle(file);
}

void Maptool::setup()
{
	
	//처음 컨트롤 상태는 지형으로
	_ctrSelect = CTRL_TERRAINDRAW;
	
	

	//타일 영역
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			PTILE Tile;
			Tile = new TILE;
			SetRect(&Tile->rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
			_vTile.push_back(Tile);

			
		}
	}

	for (int i = 0; i <_width * _height; ++i)
	{
		_vTile[i]->terrainFrameX = 1;
		_vTile[i]->terrainFrameY = 0;
		_vTile[i]->objFrameX = 0;
		_vTile[i]->objFrameY = 0;
		_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
		_vTile[i]->obj = OBJ_NONE;

		_tiles[i].terrainFrameX = _vTile[i]->terrainFrameX;
		_tiles[i].terrainFrameY = _vTile[i]->terrainFrameY;
		_tiles[i].objFrameX = _vTile[i]->objFrameX;
		_tiles[i].objFrameY = _vTile[i]->objFrameY;
		_tiles[i].terrain = _vTile[i]->terrain;
		_tiles[i].obj = _vTile[i]->obj;
	}
}

void Maptool::setSample()
{
	_vSampleTile.clear();
	//카메라 기준점
	D2D1_RECT_F _rc = CAMERAMANAGER->getScreen();
	//타일셋 먼저 세팅
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			PSTILE sampleTile;
			sampleTile = new STILE;

			sampleTile->terrainFrameX = j;
			sampleTile->terrainFrameY = i;

			//타일셋에 렉트를 씌움
			SetRect(&sampleTile->rcTile,
				(_rc.right - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE,
				_rc.top,
				(_rc.right - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE + TILESIZE,
				_rc.top + (i * TILESIZE + TILESIZE));
			_vSampleTile.push_back(sampleTile);
		}
	}
}

void Maptool::setMap()
{
	
	//타일셋에 내가 그리고싶은 타일 또는 오브젝트 클릭
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		if (PtInRect(&_vSampleTile[i]->rcTile, _ptMouse))
		{
			_currentTile.x = _vSampleTile[i]->terrainFrameX;
			_currentTile.y = _vSampleTile[i]->terrainFrameY;
			break;
		}
	}

	for (int i = 0; i < _width * _height; ++i)
	{

		if (PtInRect(&_vTile[i]->rc, _ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
			
				_vTile[i]->terrainFrameX = _currentTile.x;
				_vTile[i]->terrainFrameY = _currentTile.y;
			
				_vTile[i]->terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
			
				_vTile[i]->objFrameX = _currentTile.x;
				_vTile[i]->objFrameY = _currentTile.y;
			
				_vTile[i]->obj = objSelect(_currentTile.x, _currentTile.y);
			}

			else if (_ctrSelect == CTRL_ERASER)
			{
				_vTile[i]->terrainFrameX = NULL;
				_vTile[i]->terrainFrameY = NULL;
				_vTile[i]->objFrameX = NULL;
				_vTile[i]->objFrameY = NULL;
				_vTile[i]->obj = OBJ_NONE;
			}
			else if (_ctrSelect == CTRL_END)
			{
				_vTile[i]->terrainFrameX = _vSampleTile[5]->terrainFrameX;
				_vTile[i]->terrainFrameY = _vSampleTile[0]->terrainFrameY;
				_vTile[i]->objFrameX = NULL;
				_vTile[i]->objFrameY = NULL;
				_vTile[i]->terrain = TR_BLOCK;
			}

			InvalidateRect(_hWnd, NULL, false);
			break;
		}
		_tiles[i].terrainFrameX = _vTile[i]->terrainFrameX;
		_tiles[i].terrainFrameY = _vTile[i]->terrainFrameY;
		_tiles[i].objFrameX = _vTile[i]->objFrameX;
		_tiles[i].objFrameY = _vTile[i]->objFrameY;
		_tiles[i].terrain = _vTile[i]->terrain;
		_tiles[i].obj = _vTile[i]->obj;
	}

}



void Maptool::minimap()
{
	

	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	
	for (int i = 0; i < _width * _height; ++i)
	{
		_maptile[type]->frameRender(
			rc.left+(_vTile[i]->rc.left/(TILESIZE/3)), rc.bottom - (TILESIZE * 3) +(_vTile[i]->rc.top / (TILESIZE/3)),
			_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY, MINITILESIZE, MINITILESIZE);
		
		if (_vTile[i]->obj == OBJ_NONE) continue;
		_object->frameRender(
			rc.left + (_vTile[i]->rc.left / (TILESIZE / 3)), rc.bottom  -(TILESIZE*3)+ (_vTile[i]->rc.top / (TILESIZE / 3)),
			_vTile[i]->objFrameX, _vTile[i]->objFrameY, MINITILESIZE, MINITILESIZE);
	}
}



TERRAIN Maptool::terrainSelect(int frameX, int frameY)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j < 15; j++)
		{
			if (frameX==j && frameY==i)
			{
				return TR_BLOCK;
			}
		}
	}
	
	return TR_GRASS;
}

OBJECT Maptool::objSelect(int frameX, int frameY)
{
	if ((frameX ==6  && frameY == 0)&&
		(frameX ==6 && frameY == 3)&&
		(frameX ==6 && frameY == 6)&&
		(frameX ==6 && frameY == 9)&&
		(frameX == 15 && frameY == 0) &&
		(frameX == 15 && frameY == 3) &&
		(frameX == 15 && frameY == 6) &&
		(frameX == 15 && frameY == 9))
	{
		return OBJ_BLOCK;
	}
	else

	return OBJ_BLOCK;
}

