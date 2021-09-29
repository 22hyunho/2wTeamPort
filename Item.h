#pragma once

#define ITEMSIZE 32 //item 폴더에 있는 image는 공통 32*32입니당

enum ITEMTYPE
{
	ITEM_FOOD,
	ITEM_HOLD,
	ITEM_TM,		
	ITEM_THROW,
	ITEM_ORB,
	ENDITEMTYPE //^^b
};

class Item
{
protected:
	RECT _body;				//충돌 사각형
	dImage* _img;			//이미지
	float _x, _y;			//x, y 좌표
	int _value;				//status에 변화 줄
	wstring _name;			//인벤토리 이름표시용
	wstring _itemInfo;		//인벤토리 아이템 한줄소개
	wstring _itemInfoLong;	//인벤토리 아이템 설명란 소개
	int _num;				//아이템 넘버
	int _type;				//아이템 타입

	bool _use;				//아이템 사용 여부

	//====================throw====================//
	bool _isThrow;			//throw 아이템 던졌는지
	float _fireX, _fireY;
	float _angle;
	//float _speed; -> 타일사이즈 기준으로 update때마다 갱신

public:
	Item() {};
	~Item() {};

	virtual HRESULT init(float x, float y, float angle) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();

	//아이템 사용
	//void useItem(int value);	//도핑약 X

	void eatItem(int value); //{ return ???; }; <-?
	//Item* giveItem() { return this; }; //반환값이 아이템 포인터
	
	//throw
	//void throwItem(float x, float y, float angle);
	//void itemMove();




	//get-set
	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	int getType() { return _type; }

	int getValue() { return _value; }

	wstring getName() { return _name; }
	int getNum() { return _num; }
	wstring getItemInfo() { return _itemInfo; }
	wstring getitemInfoLong() { return _itemInfoLong; }

	bool getUse() { return _use; }
	void setUse() { _use = true; }

	RECT getBody() { return _body; }
	dImage* getImage() { return _img; }
};