#pragma once
#include "gameNode.h"
#include "Map.h"
#include "ItemControl.h"

class Stage : public gameNode
{
private:
	Map * _map;
	ItemControl * _itemControl;
public:
	Stage();
	~Stage();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

};

