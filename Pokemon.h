#pragma once
#include "PokemonType.h"




class Pokemon
{
protected:
	//현재 이미지 & 상태 및 초상화
	dImage* _currentImage;
	dImage* _stateImage[END_POKEMON_STATE];
	POKEMON_STATE _state;
	dImage* _portrait;

	bool _death;
	float _opacity;

	//이미지 프레임 및 카운트
	int _frameX;
	int _frameY;	//(== direct)
	float _angle;

	float _frameCount;					//frameCount
	float _count[END_POKEMON_STATE];	//frame넘기는 interval

	//상태별 미세조정
	float _tuningX;
	float _tuningY;
	bool _jump;

	//attack 관련 변수
	float _interceptX;
	float _interceptY;
	float _gradient;
	float _tmpCount;
	bool _attack;
	bool _sattack;






	//이름 & 도감 번호
	wstring _name;
	int _num;

	//스탯
	STAT _pokemonValue;

	//타입 & 특성
	POKEMON_TYPE _type[2];

	//특성 _passive;

	//상태이상
	//현재 상태 : { 얼음, 수면, 마비, 독, 화상, 혼란, 헤롱헤롱, 노멀 }

	//스탯(개체값)

	//배울 수 있는 기술(스킬)
	vector<int> _skill;
	//레벨업으로 배우는 기술(스킬)
	//map<num, int>

	//진화 레벨
	//int _revolution = 16; (16에 진화한다는 뜻) -> 0이면 진화 안함

public:
	virtual HRESULT init();
	void release();

	void update();
	void render(float x, float y);


	void controlFrame();
	void changeDirect(int direct);
	void changeState(POKEMON_STATE state);


	void tuneIdle();
	void tuneAttack();
	void tuneHurt();
	float attackRange(float x);



	//=================== 접근자 ===================//
	dImage* getImage() { return _currentImage; }
	POKEMON_STATE getState() { return _state; }
	dImage* getPortrait() { return _portrait; }

	bool getDeath() { return _death; }
	void setDeath(bool death) { _death = death; }

	float getAngle() { return _angle; }
	int getDirect() { return _frameY; }
	void setDirect(int direct) { _frameY = direct; }

	bool getAttack() { return _attack; }
	void setAttack(bool attack) { _attack = attack; }
	bool getSattack() { return _sattack; }
	void setSattack(bool sattack) { _sattack = sattack; }

	wstring getName() { return _name; }
	int getNum() { return _num; }

	STAT getPokemonValue() { return _pokemonValue; }

	POKEMON_TYPE* getPokemonType() { return _type; }

	vector<int> getSkill() { return _skill; }
};

