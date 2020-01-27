#include "stdafx.h"
#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

HRESULT Map::init()
{
	_img = IMAGEMANAGER->addImage("Stage", "images/Stage.bmp", 717, 600, false, COLOR_MAGENTA);

	return S_OK;
}

void Map::release()
{
	IMAGEMANAGER->deleteImage("Stage");
	_img = nullptr;
}

void Map::update()
{

}

void Map::render()
{
	_img->render(getMemDC());
}
