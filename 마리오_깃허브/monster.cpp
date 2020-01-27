#include "stdafx.h"
#include "monster.h"


monster::monster()
{
}


monster::~monster()
{
}

HRESULT monster::init()
{
	st_obstacle.obstacle_Image[1] = IMAGEMANAGER->addImage("������ֹ�_1", "images/������ֹ�_2.bmp",WINSIZEX + 400,WINSIZEY -180, 96 * 3, 32 * 2,true, RGB(255, 0, 255));

	st_obstacle.monster_Image[1] = IMAGEMANAGER->addImage(  "������",  "images/������.bmp", WINSIZEX - 50, WINSIZEY - 200, 48*2, 48*2, true, RGB(255, 0, 255));
	st_obstacle.monster_Image[0] = IMAGEMANAGER->addFrameImage("��", "images/�Ĺ�.bmp", WINSIZEX - 50, WINSIZEY - 280, 40*3 , 52 * 3, 2, 2, true, RGB(255, 0, 255));

	//st_obstacle.monster_Image[2] = IMAGEMANAGER->addFrameImage("�ź��̿�", "images/32/������.bmp", 78 * 3, 52 * 2, 3, 2, true, RGB(255, 0, 255));

	//��ֹ� �ʱ�ȭ
	st_obstacle.obstacle_Image[0] = IMAGEMANAGER->addImage("������ֹ�", "images/������ֹ�.bmp",   WINSIZEX / 2+500, WINSIZEY / 2-100, 48 * 3, 32 * 3, true, RGB(255, 0, 255));
	


	//���������� question mark�ڽ�
	st_obstacle.obstacle_Image[2] = IMAGEMANAGER->addImage("������ֹ�_2", "images/������ֹ�_3.bmp"			,WINSIZEX *2	,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[3] = IMAGEMANAGER->addImage("������ֹ�_3", "images/������ֹ�_3-���纻(2).bmp",WINSIZEX *2+50,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[4] = IMAGEMANAGER->addImage("������ֹ�_4", "images/������ֹ�_3-���纻(3).bmp",WINSIZEX *2+100,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));

	st_obstacle.obstacle_Image[5] = IMAGEMANAGER->addImage("������ֹ�_5", "images/������ֹ�_3-���纻(4).bmp",WINSIZEX *2+150,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[6] = IMAGEMANAGER->addImage("������ֹ�_6", "images/������ֹ�_3-���纻(5).bmp",WINSIZEX *2+200,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[7] = IMAGEMANAGER->addImage("������ֹ�_7", "images/������ֹ�_3-���纻(6).bmp",WINSIZEX *2+250,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));

	//������ ���׽�Ű�� ����
	//st_obstacle.line_Of_Obstacle[0] = RectMakeCenter(WINSIZEX - 55, WINSIZEY - 200,122,70);

	count = 0;
	move = 0;
	check = false;
	return S_OK;
}

void monster::release()
{

}

void monster::update()
{

	//�� �����̴� ���
	count++;
	if (count % 10== 0)
	{
		st_obstacle.monster_Image[0]->setFrameX(0);
	}
	if (count % 20== 0)
	{
		st_obstacle.monster_Image[0]->setFrameX(1);
	}


	
	//turtleMove(st_obstacle.monster_Rc[2], st_obstacle.monster_Rc[1],3);


	//��ǥ������ �浹�ϰ� �����

}
void monster::render()
{
		//IMAGEMANAGER->frameRender("�ź��̿�", getMemDC(), st_obstacle.monster_Rc[2].left, st_obstacle.monster_Rc[2].top, st_obstacle.monster_Image[2]->getFrameX(), st_obstacle.monster_Image[2]->getFrameY());
		IMAGEMANAGER->frameRender("��", getMemDC(), st_obstacle.monster_Image[0]->getBoundingBoxFrame().left, st_obstacle.monster_Image[0]->getBoundingBoxFrame().top, st_obstacle.monster_Image[0]->getFrameX(), st_obstacle.monster_Image[0]->getFrameY());
		IMAGEMANAGER->render("������ֹ�", getMemDC(), st_obstacle.obstacle_Image[0]->getBoundingBox().left, st_obstacle.obstacle_Image[0]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_1", getMemDC(), st_obstacle.obstacle_Image[1]->getBoundingBox().left, st_obstacle.obstacle_Image[1]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_2", getMemDC(), st_obstacle.obstacle_Image[2]->getBoundingBox().left, st_obstacle.obstacle_Image[2]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_3", getMemDC(), st_obstacle.obstacle_Image[3]->getBoundingBox().left, st_obstacle.obstacle_Image[3]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_4", getMemDC(), st_obstacle.obstacle_Image[4]->getBoundingBox().left, st_obstacle.obstacle_Image[4]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_5", getMemDC(), st_obstacle.obstacle_Image[5]->getBoundingBox().left, st_obstacle.obstacle_Image[5]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_6", getMemDC(), st_obstacle.obstacle_Image[6]->getBoundingBox().left, st_obstacle.obstacle_Image[6]->getBoundingBox().top);
		IMAGEMANAGER->render("������ֹ�_7", getMemDC(), st_obstacle.obstacle_Image[7]->getBoundingBox().left, st_obstacle.obstacle_Image[7]->getBoundingBox().top);
	
		//Rectangle(getMemDC(), st_obstacle.line_Of_Obstacle[0].left, st_obstacle.line_Of_Obstacle[0].top, st_obstacle.line_Of_Obstacle[0].right, st_obstacle.line_Of_Obstacle[0].bottom);


	IMAGEMANAGER->render("������", getMemDC(), st_obstacle.monster_Image[1]->getBoundingBox().left, st_obstacle.monster_Image[1]->getBoundingBox().top);
	IMAGEMANAGER->render("��", getMemDC(), st_obstacle.monster_Image[1]->getBoundingBox().left, st_obstacle.monster_Image[1]->getBoundingBox().top);

	//�簢�� üũ��
	if (KEYMANAGER->isToggleKey(VK_F1))
	{

			//���� ��ֹ�_1
			Rectangle(getMemDC(), st_obstacle.monster_Image[1]->getBoundingBox().left, st_obstacle.monster_Image[1]->getBoundingBox().top, st_obstacle.monster_Image[1]->getBoundingBox().right, st_obstacle.monster_Image[1]->getBoundingBox().bottom);

			//������
			for (int i = 0; i < 8; i++)
			{
				Rectangle(getMemDC(), st_obstacle.obstacle_Image[i]->getBoundingBox().left, st_obstacle.obstacle_Image[i]->getBoundingBox().top, st_obstacle.obstacle_Image[i]->getBoundingBox().right, st_obstacle.obstacle_Image[i]->getBoundingBox().bottom);
			}
			//��
			Rectangle(getMemDC(), st_obstacle.monster_Image[0]->getBoundingBoxFrame().left, st_obstacle.monster_Image[0]->getBoundingBoxFrame().top, st_obstacle.monster_Image[0]->getBoundingBoxFrame().right, st_obstacle.monster_Image[0]->getBoundingBoxFrame().bottom);
			/*for (int i = 0; i < 40; i++)
			
			{
				Rectangle(getMemDC(), st_obstacle.obstacle_Image[i]->getBoundingBox().left, st_obstacle.obstacle_Image[i]->getBoundingBox().top, st_obstacle.obstacle_Image[i]->getBoundingBox().right, st_obstacle.obstacle_Image[i]->getBoundingBox().bottom);
			}*/
	}

}
//�����ֹ� ��ġ ���ڸ��� ����Ű�� ī�޶�
void monster::LeftCamera()
{
	for (int i = 0; i < 8; i++)
	{
		st_obstacle.obstacle_Image[i]->setBoundingBox(-5);
	}

		st_obstacle.monster_Image[0]->setBoundingBox(-5);
		st_obstacle.monster_Image[1]->setBoundingBox(-5);
		st_obstacle.line_Of_Obstacle[0].left += 5;
		st_obstacle.line_Of_Obstacle[0].right += 5;
		test.left += 5;
		test.right += 5;
}
void monster::RightCamera()
{

	for (int i = 0; i < 8; i++)
	{
		st_obstacle.obstacle_Image[i]->setBoundingBox(5);


	}
		st_obstacle.monster_Image[0]->setBoundingBox(5);
		st_obstacle.monster_Image[1]->setBoundingBox(5);
		st_obstacle.line_Of_Obstacle[0].left -= 5;
		st_obstacle.line_Of_Obstacle[0].right -= 5;
		test.left -= 5;
		test.right -= 5;
}


//�ź��� �����̱� 
void monster::turtleMove(RECT& move, RECT& collision, int speed)
{
	static bool isRight = false;
	if (move.right >= collision.left)
	{
		isRight = false;
	}
	if (move.left<=50)
	{
		isRight = true;
	}
	if (isRight)
	{
	OffsetRect(&move, speed, 0);
	st_obstacle.monster_Image[2]->setFrameY(0);
	for (int i = 0; i <2;i++)
	{
	count++;
	if (count % 20 == 0)
	{
		st_obstacle.monster_Image[2]->setFrameX(i);
	}
	}
	}
	else
	{
		st_obstacle.monster_Image[2]->setFrameY(1);
		OffsetRect(&move, -speed, 0);
		//st_obstacle.monster_Image[2]->setFrameX(1);
	
		for (int i = 1; i <3 ; i++)
		{
			count++;
			if (count % 20 == 0)
			{
				st_obstacle.monster_Image[2]->setFrameX(i);
			}
		}
	
	}
}
