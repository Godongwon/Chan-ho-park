#pragma once
#include"gameNode.h"
#include"image.h"
#include"soundManager.h"
class soundbox : gameNode
{

private:
	image* button_Of_Music[4];
	RECT Button_Play;
	RECT Button_Stop;
	RECT Button_Resume;
	RECT Button_Previous;
	RECT Button_Next;
	RECT Button_Pause;
	//음악재생용 박스
	RECT temp;
	bool Check_Play;
	bool Check_Resume;

public:
	void delete_image();
	void init_image();
	void init_sound();
	
public:
	HRESULT init();	//초기화
	void release();//해제
	void update();//연산하는곳
	void render(/*HDC hdc*/);//그리는곳
	//RECT* getMonster() { return &st_obstacle.line_Of_Obstacle[0]; }

	

};

