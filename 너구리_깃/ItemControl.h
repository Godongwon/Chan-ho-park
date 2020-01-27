#pragma once
#include "Carrot.h"
#include "Jar.h"

class ItemControl :public gameNode
{
private:
	typedef vector<Item *> vItems;
private:
	vItems _items;
	vItems::iterator _itemsIter;
public:
	void init_carrots();
	void draw_carrots();
	void delete_carrotsAll();
	void init_jars();
	void draw_jars();
	void delete_jarsAll();
public:
	ItemControl();
	~ItemControl();

	HRESULT init();
	void release();
	void update();
	void render();
};

