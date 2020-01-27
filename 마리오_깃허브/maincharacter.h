#pragma once
#include"gameNode.h"
//�����̽�, ���� , �ɱ�, �����̵�
#include"monster.h"

struct tagMario
{
	image *mario_Image[3];
	RECT mario_Rect;
	//////////////////
	image *monster_Image[2];
	//////////////////
	float gravity;
	float jump_power;

	int count;
	int index;

	int run_count;
	int run_index;


	int jump_count;
	int jump_index;


	bool isJump;
	bool isLeft;
	bool isDead;

	MARIODIRECTION mario_direction;

	
};
class maincharacter : public gameNode
{
private:
	//maincharacter cpp���Ͽ��� tagobstacle �ؾߵȴ�.
	RECT ground;
	tagMario _mario;
	

	monster* _monster;
private:
	bool check;
	bool isLeftArrow_keyDown;
	
public:
	maincharacter();
	~maincharacter();
	bool check_Collision;

	
	//void setPlayerRect(RECT rc) { rc = _mario.mario_Rect; }
	HRESULT init();
	void release();
	void update();
	void render();
	void KeyControl();
	void frame(MARIODIRECTION mario_direction);

	tagMario* getPlayerInfo() { return &_mario; }
	//RECT getPlayer() { return _mario.mario_Rect; }
	void setPlayerPos(LONG left, LONG right) { _mario.mario_Rect.left = left , _mario.mario_Rect.right = right; }
};

