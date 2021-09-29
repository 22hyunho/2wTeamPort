#pragma once

class Player;

class Pattern
{
protected:
	Player* _player;

public:
	virtual HRESULT init(Player* player);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};