#pragma once
#include"gameNode.h"
#include"scene1.h"
#include"scene2.h"
#include"soundTest.h"
#include"soundbox.h"
class mainGame :  public gameNode
{
private:
	RECT rc;
	soundbox* m_Sound_Box;
public:
	mainGame();
	~mainGame();

	soundbox* getSoundInfo() { return m_Sound_Box; }
	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

