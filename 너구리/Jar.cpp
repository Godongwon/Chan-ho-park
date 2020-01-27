#include "stdafx.h"
#include "Jar.h"

Jar::Jar()
{
}

Jar::~Jar()
{
}

HRESULT Jar::init()
{
	_width = 50;
	_height = 50;
	_type = "Jar";
	_img = IMAGEMANAGER->addImage(_type, "images/Jar.bmp", _width, _height, true, COLOR_MAGENTA);
	_fDebug = false;

	return S_OK;
}

void Jar::release()
{

	_img = nullptr;
}

void Jar::update()
{
}

void Jar::render()
{
	_img->render(getMemDC(), _rc.left, _rc.top);
}
