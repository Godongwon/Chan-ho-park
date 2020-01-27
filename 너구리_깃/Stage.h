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

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

};

