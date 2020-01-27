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
	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	
};

