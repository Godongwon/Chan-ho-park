#pragma once
#include "Item.h"

class Carrot : public Item
{
public:
	Carrot();
	~Carrot();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
};

