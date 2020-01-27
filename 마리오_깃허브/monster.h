#pragma once
#include"gameNode.h"
#define OBSTACLE_IMAGE 10
struct tagobstacle
{
	image *monster_Image[10];
	image *obstacle_Image[OBSTACLE_IMAGE];
	RECT line_Of_Obstacle[4];
};

class monster : public gameNode
{
private:
	
	//maincharacter *_mario;
	int index;
	int count;
	int move;
	bool check;
	tagobstacle st_obstacle;
public:
	
	monster();
	~monster();


	RECT test;

	HRESULT init();
	void release();
	void update();
	void render();
	void LeftCamera();
	
	void RightCamera();
	void turtleMove(RECT& move, RECT& collision, int speed);
	RECT* getMonster() { return &st_obstacle.line_Of_Obstacle[0]; }
	RECT getTest() { return test; }
	
};

