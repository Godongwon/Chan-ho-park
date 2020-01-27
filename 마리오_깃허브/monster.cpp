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
	st_obstacle.obstacle_Image[1] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_1", "images/´«¸ÊÀå¾Ö¹°_2.bmp",WINSIZEX + 400,WINSIZEY -180, 96 * 3, 32 * 2,true, RGB(255, 0, 255));

	st_obstacle.monster_Image[1] = IMAGEMANAGER->addImage(  "ÆÄÀÌÇÁ",  "images/ÆÄÀÌÇÁ.bmp", WINSIZEX - 50, WINSIZEY - 200, 48*2, 48*2, true, RGB(255, 0, 255));
	st_obstacle.monster_Image[0] = IMAGEMANAGER->addFrameImage("²É", "images/½Ä¹°.bmp", WINSIZEX - 50, WINSIZEY - 280, 40*3 , 52 * 3, 2, 2, true, RGB(255, 0, 255));

	//st_obstacle.monster_Image[2] = IMAGEMANAGER->addFrameImage("°ÅºÏÀÌ¿ì", "images/32/²¿ºÏÀÌ.bmp", 78 * 3, 52 * 2, 3, 2, true, RGB(255, 0, 255));

	//Àå¾Ö¹° ÃÊ±âÈ­
	st_obstacle.obstacle_Image[0] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°", "images/´«¸ÊÀå¾Ö¹°.bmp",   WINSIZEX / 2+500, WINSIZEY / 2-100, 48 * 3, 32 * 3, true, RGB(255, 0, 255));
	


	//µ¿Àü³ª¿À´Â question mark¹Ú½º
	st_obstacle.obstacle_Image[2] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_2", "images/´«¸ÊÀå¾Ö¹°_3.bmp"			,WINSIZEX *2	,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[3] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_3", "images/´«¸ÊÀå¾Ö¹°_3-º¹»çº»(2).bmp",WINSIZEX *2+50,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[4] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_4", "images/´«¸ÊÀå¾Ö¹°_3-º¹»çº»(3).bmp",WINSIZEX *2+100,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));

	st_obstacle.obstacle_Image[5] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_5", "images/´«¸ÊÀå¾Ö¹°_3-º¹»çº»(4).bmp",WINSIZEX *2+150,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[6] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_6", "images/´«¸ÊÀå¾Ö¹°_3-º¹»çº»(5).bmp",WINSIZEX *2+200,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));
	st_obstacle.obstacle_Image[7] = IMAGEMANAGER->addImage("´«¸ÊÀå¾Ö¹°_7", "images/´«¸ÊÀå¾Ö¹°_3-º¹»çº»(6).bmp",WINSIZEX *2+250,WINSIZEY/2,  32 *1.5, 32 *1.5,true, RGB(255, 0, 255));

	//ÆÄÀÌÇÁ ¹ö±×½ÃÅ°´Â ¶óÀÎ
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

	//²É ¿òÁ÷ÀÌ´Â ¸ð¼Ç
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


	//ÁÂÇ¥°ªÀ¸·Î Ãæµ¹ÇÏ°Ô ¸¸µé±â

}
void monster::render()
{
		//IMAGEMANAGER->frameRender("°ÅºÏÀÌ¿ì", getMemDC(), st_obstacle.monster_Rc[2].left, st_obstacle.monster_Rc[2].top, st_obstacle.monster_Image[2]->getFrameX(), st_obstacle.monster_Image[2]->getFrameY());
		IMAGEMANAGER->frameRender("²É", getMemDC(), st_obstacle.monster_Image[0]->getBoundingBoxFrame().left, st_obstacle.monster_Image[0]->getBoundingBoxFrame().top, st_obstacle.monster_Image[0]->getFrameX(), st_obstacle.monster_Image[0]->getFrameY());
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°", getMemDC(), st_obstacle.obstacle_Image[0]->getBoundingBox().left, st_obstacle.obstacle_Image[0]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_1", getMemDC(), st_obstacle.obstacle_Image[1]->getBoundingBox().left, st_obstacle.obstacle_Image[1]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_2", getMemDC(), st_obstacle.obstacle_Image[2]->getBoundingBox().left, st_obstacle.obstacle_Image[2]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_3", getMemDC(), st_obstacle.obstacle_Image[3]->getBoundingBox().left, st_obstacle.obstacle_Image[3]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_4", getMemDC(), st_obstacle.obstacle_Image[4]->getBoundingBox().left, st_obstacle.obstacle_Image[4]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_5", getMemDC(), st_obstacle.obstacle_Image[5]->getBoundingBox().left, st_obstacle.obstacle_Image[5]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_6", getMemDC(), st_obstacle.obstacle_Image[6]->getBoundingBox().left, st_obstacle.obstacle_Image[6]->getBoundingBox().top);
		IMAGEMANAGER->render("´«¸ÊÀå¾Ö¹°_7", getMemDC(), st_obstacle.obstacle_Image[7]->getBoundingBox().left, st_obstacle.obstacle_Image[7]->getBoundingBox().top);
	
		//Rectangle(getMemDC(), st_obstacle.line_Of_Obstacle[0].left, st_obstacle.line_Of_Obstacle[0].top, st_obstacle.line_Of_Obstacle[0].right, st_obstacle.line_Of_Obstacle[0].bottom);


	IMAGEMANAGER->render("ÆÄÀÌÇÁ", getMemDC(), st_obstacle.monster_Image[1]->getBoundingBox().left, st_obstacle.monster_Image[1]->getBoundingBox().top);
	IMAGEMANAGER->render("´«", getMemDC(), st_obstacle.monster_Image[1]->getBoundingBox().left, st_obstacle.monster_Image[1]->getBoundingBox().top);

	//»ç°¢Çü Ã¼Å©¿ë
	if (KEYMANAGER->isToggleKey(VK_F1))
	{

			//´«¸Ê Àå¾Ö¹°_1
			Rectangle(getMemDC(), st_obstacle.monster_Image[1]->getBoundingBox().left, st_obstacle.monster_Image[1]->getBoundingBox().top, st_obstacle.monster_Image[1]->getBoundingBox().right, st_obstacle.monster_Image[1]->getBoundingBox().bottom);

			//ÆÄÀÌÇÁ
			for (int i = 0; i < 8; i++)
			{
				Rectangle(getMemDC(), st_obstacle.obstacle_Image[i]->getBoundingBox().left, st_obstacle.obstacle_Image[i]->getBoundingBox().top, st_obstacle.obstacle_Image[i]->getBoundingBox().right, st_obstacle.obstacle_Image[i]->getBoundingBox().bottom);
			}
			//²É
			Rectangle(getMemDC(), st_obstacle.monster_Image[0]->getBoundingBoxFrame().left, st_obstacle.monster_Image[0]->getBoundingBoxFrame().top, st_obstacle.monster_Image[0]->getBoundingBoxFrame().right, st_obstacle.monster_Image[0]->getBoundingBoxFrame().bottom);
			/*for (int i = 0; i < 40; i++)
			
			{
				Rectangle(getMemDC(), st_obstacle.obstacle_Image[i]->getBoundingBox().left, st_obstacle.obstacle_Image[i]->getBoundingBox().top, st_obstacle.obstacle_Image[i]->getBoundingBox().right, st_obstacle.obstacle_Image[i]->getBoundingBox().bottom);
			}*/
	}

}
//¸ðµçÀå¾Ö¹° À§Ä¡ ±×ÀÚ¸®¿¡ °íÁ¤Å°´Â Ä«¸Þ¶ó
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


//°ÅºÏÀÌ ¿òÁ÷ÀÌ±â 
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
