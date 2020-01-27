#pragma once
#include "gameNode.h"

class Item : public gameNode
{
protected :
	image * _img;
	RECT _rc;
	string _type;
	int _width;
	int _height;
	bool _fDebug;

public:
	//항아리 움직일때
	void set_rc(RECT rc) { _rc = rc; }
	RECT get_rc() { return _rc; }
	string get_type() { return _type; }
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

