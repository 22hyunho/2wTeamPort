#pragma once


//지형
enum TERRAIN
{
	TR_BLOCK, TR_WATER, TR_GRASS, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_BLOCK,
	OBJ_TRAP, OBJ_TRAP1, OBJ_TRAP2,
	OBJ_STAIR,
	OBJ_NONE
};

//컨트롤
enum CTRL
{
	CTRL_TERRAINDRAW,	//지형		
	CTRL_OBJDRAW,		//오브젝트	
	CTRL_ERASER,		//지우개		
	CTRL_END
};

//타일 글자타입
enum Tile
{
	Unused = '~',
	Floor = '!',
	Corridor = '#',
	Wall = '$',
	ClosedDoor = '%',
	UpStairs = '&',
	DownStairs = '(',
	LeftTriWall = ')',
	RightTriWall = '*',
	TopTriWall = '+',
	BottomTriWall = ',',
	LeftOpenWall = '-',
	RightOpenWall = '.',
	TopOpenWall = '/',
	BottomOpenWall = '0',
	LeftOpenCorner = '1',
	LeftCorner = '2',
	RightOpenCorner = '3',
	RightCorner = '4',
	LeftOpenBottom = '5',
	LeftBottom = '6',
	RightOpenBottom = '7',
	RightBottom = '8',
	VerticalWall = '9',
	VerticalLeftWall = ':',
	VerticalRightWall = ';',
	HorizontalTopWall = '<',
	HorizontalBottomWall = '=',
	HorizontalWall = '>',
	LeftBlockWall = '?',
	RightBlockWall = '@',
	TopBlockWall = 'A',
	BottomBlockWall = 'B',
	VerticalTopRight = 'C',
	VerticalTopLeft = 'D',
	VerticalBottomRight = 'E',
	VerticalBottomLeft = 'F',
	HorizontalTopRight = 'G',
	HorizontalTopLeft = 'H',
	HorizontalBottomRight = 'I',
	HorizontalBottomLeft = 'J',
	AllOpenRight = 'K',
	AllOpenLeft = 'L',
	OpenConnectTopLeft = 'M',
	OpenConnectTopRight = 'N',
	OpenConnectBottomLeft = 'O',
	OpenConnectBottomRight = 'P',
	LeftTopBlockCorner = 'Q',
	RightTopBlockCorner = 'R',
	LeftBottomBlockCorner = 'S',
	RightBottomBlockCorner = 'T',
	ClearTrap = 'U',
	PowerTrap = 'V'

};

//각객체 방향
enum Direction
{
	North,
	South,
	West,
	East,
	DirectionCount
};

//타일 정보 담은 구조체
typedef struct tagTile
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			x;
	int			y;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
}TILE, *PTILE;

//타일셋 정보 담을 구조체
typedef struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
}STILE, *PSTILE;

//현재 타일 받아올 구조체
struct tagCurrentTile
{
	int x;
	int y;
};