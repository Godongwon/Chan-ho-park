#pragma once
#include "Item.h"

class Jar : public Item
{
public:
	Jar();
	~Jar();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
};

