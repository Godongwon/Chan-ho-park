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
	//��������� �ڽ�
	RECT temp;
	bool Check_Play;
	bool Check_Resume;

public:
	void delete_image();
	void init_image();
	void init_sound();
	
public:
	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render(/*HDC hdc*/);//�׸��°�
	//RECT* getMonster() { return &st_obstacle.line_Of_Obstacle[0]; }

	

};

