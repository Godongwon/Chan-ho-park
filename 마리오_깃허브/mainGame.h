#pragma once
#include"gameNode.h"

//#include"monster.h"
#include"Map.h"
class mainGame :  public gameNode
{
private:
	//maincharacter * m_mario_character;
	//monster *m_monster;
	Map* m_map;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	
};

