#include "stdafx.h"
#include "Item.h"

void Item::show_rc()
{
	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
}

void Item::init_rc(int x, int y)
{
	_rc = RectMake(x, y, _width, _height);
}

Item::Item()
{
}

Item::~Item()
{
}

HRESULT Item::init()
{
	return S_OK;
}

void Item::release()
{
}

void Item::update()
{
}

void Item::render()
{
}
