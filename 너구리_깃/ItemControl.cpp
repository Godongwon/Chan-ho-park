#include "stdafx.h"
#include "ItemControl.h"

void ItemControl::init_carrots()
{
	Carrot * carrot = new Carrot;
	carrot->init();
	carrot->init_rc(110, 148);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(467, 148);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(556, 234);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(177, 320);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(556, 320);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(21, 406);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(556, 406);
	_items.push_back(carrot);
	carrot = nullptr;
	carrot = new Carrot;
	carrot->init();
	carrot->init_rc(199, 491);
	_items.push_back(carrot);
	carrot = nullptr;

}
void ItemControl::draw_carrots()
{
	_itemsIter = _items.begin();
	for (; _itemsIter != _items.end(); _itemsIter++)
	{
		(*_itemsIter)->render();
	}
}
void ItemControl::delete_carrotsAll()
{
	_itemsIter = _items.begin();
	for (;_itemsIter != _items.end();)
	{
		(*_itemsIter)->release();
		_itemsIter = _items.erase(_itemsIter);
	}
	swap(_items, vItems());
}
//(21, 148)(377, 148)(21, 234)(399, 406)
void ItemControl::init_jars()
{
	Jar * jar = new Jar;
	jar->init();
	jar->init_rc(21, 148);
	_items.push_back(jar);
	jar = nullptr;
	jar = new Jar;
	jar->init();
	jar->init_rc(377, 148);
	_items.push_back(jar);
	jar = nullptr;
	jar = new Jar;
	jar->init();
	jar->init_rc(21, 234);
	_items.push_back(jar);
	jar = nullptr;
	jar = new Jar;
	jar->init();
	jar->init_rc(399, 406);
	_items.push_back(jar);
	jar = nullptr;
}

void ItemControl::draw_jars()
{
	_itemsIter = _items.begin();
	for (; _itemsIter != _items.end(); _itemsIter++)
	{
		(*_itemsIter)->render();
	}
}

void ItemControl::delete_jarsAll()
{
	_itemsIter = _items.begin();
	for (; _itemsIter != _items.end();)
	{
		(*_itemsIter)->release();
		_itemsIter = _items.erase(_itemsIter);
	}
	swap(_items, vItems());
}

ItemControl::ItemControl()
{
}
ItemControl::~ItemControl()
{
}

HRESULT ItemControl::init()
{
	init_carrots();
	init_jars();
	return S_OK;
}

void ItemControl::release()
{
	delete_carrotsAll();
	delete_jarsAll();
}

void ItemControl::update()
{
}

void ItemControl::render()
{
	draw_carrots();
	draw_jars();
}
