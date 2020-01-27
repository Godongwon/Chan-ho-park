#pragma once
#include"gameNode.h"
#include"maincharacter.h"
#include"monster.h"
class Map :  public gameNode
{
private:
	maincharacter * m_mario;
	monster* m_monster;
	//tagobstacle *m_obstacle;
	//tagobstacle* m_tagobstacle;

	RECT rc;
	int move = false;
public:
	Map();
	~Map();

	
	HRESULT init();
	void release();
	void update();
	void render();

	void collision();

};

