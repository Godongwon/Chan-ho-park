#pragma once
#include "gameNode.h"
class Map : public gameNode
{
private:
	image * _img;
public:
	Map();
	~Map();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

};