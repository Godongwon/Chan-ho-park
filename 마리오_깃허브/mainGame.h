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

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

