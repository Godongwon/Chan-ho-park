#pragma once
#include"gameNode.h"
#include "Stage.h"
class mainGame :  public gameNode
{
private:
	Stage * _stg;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

