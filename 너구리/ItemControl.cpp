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
	for (; _itemsIter != _items.end();)
	{
		(*_itemsIter)->release();
		_itemsIter = _items.erase(_itemsIter);
	}
	swap(_items, vItems());
}
//======================================
//##			항아리			  ##
//======================================
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
	jar = new Jar;
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
void ItemControl::move_jars_right()
{
	RECT rc;
	_itemsIter = _items.begin();
	for (; _itemsIter != _items.end(); _itemsIter++)
	{
		if ((*_itemsIter)->get_type().compare("Jar") == 0)
		{
			rc = (*_itemsIter)->get_rc();
			rc.left += 5;
			rc.right += 5;
			(*_itemsIter)->set_rc(rc);
		}//if: 뒤적거린 아이템이 항아리라면
	}
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
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		move_jars_right();
	}
}

void ItemControl::render()
{
	draw_carrots();
	draw_jars();
}
