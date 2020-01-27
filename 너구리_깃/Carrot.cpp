#include "stdafx.h"
#include "Carrot.h"

Carrot::Carrot()
{
}

Carrot::~Carrot()
{
}

HRESULT Carrot::init()
{
	_width = 50;
	_height = 48;
	_img = IMAGEMANAGER->addImage("Carrot", "images/Carrot.bmp", _width, _height,true,COLOR_MAGENTA);
	_fDebug = false;
	return S_OK;
}

void Carrot::release()
{
	_img = nullptr;
}

void Carrot::update()
{
}

void Carrot::render()
{
	_img->render(getMemDC(), _rc.left, _rc.top);
}
