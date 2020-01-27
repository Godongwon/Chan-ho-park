#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

HRESULT Stage::init()
{
	_map = new Map;
	_map->init();
	_itemControl = new ItemControl;
	_itemControl->init();
	return S_OK;
}

void Stage::release()
{
	_map->release();
	_map = nullptr;
	_itemControl->release();
	_itemControl = nullptr;
}

void Stage::update()
{
	_map->update();
}

void Stage::render()
{
	_map->render();
	_itemControl->render();
}
