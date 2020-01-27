#pragma once
#include "gameNode.h"

class Item : public gameNode
{
protected :
	image * _img;
	RECT _rc;
	int _width;
	int _height;
	bool _fDebug;

public:
	void show_rc();
	void init_rc(int x, int y);
public:
	Item();
	~Item();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

