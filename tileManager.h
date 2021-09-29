#pragma once
#include "singletonBase.h"
#include "tileInfo.h"
#include <vector>

#define TILESIZE 48
#define MINITILESIZE 6

#define TILEX 151	//���� Ÿ�� ����
#define TILEY 151	//���� Ÿ�� ����



#define TILESIZEX TILESIZE * TILEX	//560 28 * 20
#define TILESIZEY TILESIZE * TILEY	//620 31 * 20

//Ÿ�ϼ� ����
#define SAMPLETILEX 15
#define SAMPLETILEY 4

//��Ʈ�ʵ�
#define ATTR_UNMOVE 0x00000016	//������ Ÿ��
#define ATTR_SWAMP	0x00000032	//������ �������� Ÿ��
#define ATTR_POISON	0x00000064	//�� �� �� ������~
#define ATTR_FROZEN 0x00000128	//������~
#define ATTR_WATER	0x00000256  //��


class tileManager : public singletonBase<tileManager>
{
private:
	vector<tagTile*>					_vTile;
	vector<tagSampleTile*>				_vSampleTile;
	vector<DWORD*>						_vAttribute;

	vector<char>						_vChar;
	vector<RECT>						_vRoom;
	vector<RECT>						_vExit;

	dImage* _Mapbase[8];
	dImage*	_Obbase;
	dImage* _minibase;

	tagTile _tiles[TILEX*TILEY];
	tagTile _mini[TILEX*TILEY];
	DWORD _attribute[TILEX*TILEY];
	

	int _initX;
	int _endX;
	int _initY;
	int _endY;


	int _playerX;
	int _playerY;

	int _width;
	int _height;
	int _type;
	int _floor;
	wstring _dungeonName;
	int _trapCount;
	
	//���ͷ� �ٲ㼭 ��ȣ�� �ֱ�
	vector<int> _enemyList;
	int _bossPokemon;
	int _minLevel;
	int _maxLevel;

public:
	tileManager();
	~tileManager();

	HRESULT init();										//�⺻ �̴ϼȶ�����
	HRESULT init(int width, int height, int type);		//������ �̴ϼȶ�����
	void release();
	void update();
	void render();
	void maprender();
	void setup();

	void load(const char* mapName);
	void minimap();

	void dungeon(int width, int height);
	void generate(int maxFeatures);
	bool createFeature();
	bool createFeature(int x, int y, Direction dir);
	bool makeRoom(int x, int y, Direction dir);
	bool makeCorridor(int x, int y, Direction dir);
	bool placeRect(RECT rc, char Char);
	bool placeObject(char Char);

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	void playBGM();
	void stopBGM();



	void setChar(int x, int y, char Char) { _vChar[x + y * _width] = Char; }
	void setWidth(int Width) { _width = Width; }
	void setHeight(int Height) { _height = Height; }
	void setType(int type) { _type = type; }
	void setPlayerX(int playerX) { _playerX = playerX; }
	void setPlayerY(int playerY) { _playerY = playerY; }

	int getWidth() { return _width; }
	int getHeight() { return _height; }
	int getType() { return _type; }
	int getFloor() { return _floor; }
	wstring getDungeonName() { return _dungeonName; }
	int getPlayerX() { return _playerX;}
	int getPlayerY() { return _playerY; }
	
	vector<int> getEnemyList() { return _enemyList; }
	int getBoss() { return _bossPokemon; }
	int getMinLevel() { return _minLevel; }
	int getMaxLevel() { return _maxLevel; }

	char getChar(int x, int y) { return _vChar[x + y * _width]; }

	vector<tagTile*>* getvTile() { return &_vTile; }
	vector<RECT>* getvRoom() { return &_vRoom; }



};
