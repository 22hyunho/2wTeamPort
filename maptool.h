#pragma once
#include "tileInfo.h"


class Maptool
{

private:

	vector<tagTile*>					_vTile;
	vector<tagTile*>::iterator			_viTile;
	vector<tagSampleTile*>				_vSampleTile;
	vector<tagSampleTile*>::iterator	_viSampleTile;
	vector<DWORD*>						_vAttribute;
	vector<DWORD*>::iterator			_viAttribute;


	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile _tiles[TILEX*TILEY];
	DWORD _attribute[TILEX*TILEY];	//타일속성

	dImage* _maptile[8];
	dImage* _object;
	int _pos[2];

	int _width;
	int _height;
	int _ctrSelect;
	int type;

	bool mode;

public:
	Maptool();
	~Maptool();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void save(const char * mapName);
	void load(const char * mapName);
	virtual void setup();
	virtual void setSample();
	virtual void setMap();

	void minimap();

	dImage* getMaptile() { return _maptile[8]; }
	dImage* getObject() { return _object; }

	int getType() { return type; }

	DWORD* getTileAttribute() { return _attribute; }
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
};

