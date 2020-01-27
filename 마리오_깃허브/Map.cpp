#include "stdafx.h"
#include "Map.h"


Map::Map()
{
}


Map::~Map()
{
}

HRESULT Map::init()
{
	IMAGEMANAGER->addImage("배경화면", "images/32/배경.bmp", 10240, 768, true, RGB(255, 0, 255));

	m_mario = new maincharacter;
	m_mario->init();
	m_monster = new monster;
	m_monster->init();

	//rc = RectMakeCenter(WINSIZEX - 55, WINSIZEY - 200, 122, 70);
	return S_OK;
}

void Map::release()
{
	SAFE_DELETE(m_mario);
	SAFE_DELETE(m_monster);
}

void Map::update()
{
	rc = RectMakeCenter(WINSIZEX - 55, WINSIZEY - 200, 122, 70);
	collision();
	m_mario->update();
	m_monster->update();
}

void Map::render()
{
	IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	m_mario->render();
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	
	m_monster->render();

}

void Map::collision()
{
	rc = RectMakeCenter(WINSIZEX - 55 + _camera , WINSIZEY - 200, 122, 70);
	
	
	//static bool isCheck = false;
	RECT temp1;

	
	if(IntersectRect(&temp1, &m_mario->getPlayerInfo()->mario_Rect, &rc) && KEYMANAGER->isStayKeyDown(VK_RIGHT) && m_mario->check_Collision == false)
	{   
		m_mario->getPlayerInfo()->mario_Rect.right = rc.left;
		m_mario->getPlayerInfo()->mario_Rect.left = m_mario->getPlayerInfo()->mario_Rect.right - m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth();
		m_mario->check_Collision = true;

	}   
	if (IntersectRect(&temp1, &m_mario->getPlayerInfo()->mario_Rect, &rc)&&KEYMANAGER->isStayKeyDown(VK_RIGHT) && m_mario->check_Collision==false)
	{   
		m_mario->getPlayerInfo()->mario_Rect.right = rc.left;
		m_mario->getPlayerInfo()->mario_Rect.left = m_mario->getPlayerInfo()->mario_Rect.right - m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth();
	}   
	//우측키 눌렀을시에 되는지 안되는지 검사하기 
	RECT temp2;
	if (IntersectRect(&temp2, &m_mario->getPlayerInfo()->mario_Rect, &rc) && KEYMANAGER->isStayKeyDown(VK_LEFT))
	{   
		m_mario->getPlayerInfo()->mario_Rect.left = rc.right;
		m_mario->getPlayerInfo()->mario_Rect.right = m_mario->getPlayerInfo()->mario_Rect.left + m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth();

	}   
	
	
	/*
	
	st_obstacle.monster_Image[1] //파이프
	//장애물 초기화
	st_obstacle.obstacle_Image[0]
	st_obstacle.obstacle_Image[1]
	
	*/




	//if(IntersectRect(&temp, &m_mario->getPlayerInfo()->mario_Rect, &m_monster->getMonster()->monster_Image[1]->getBoundingBox()) && (KEYMANAGER->isStayKeyDown(VK_RIGHT)))
	//{
	//	
	//	m_mario->setPlayerPos((m_mario->getPlayerInfo()->mario_Rect.right- 10) - m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth(),
	//	m_monster->getMonster()->monster_Image[1]->getBoundingBox().left - 10);																																																																																																																																																																
	//	//m_mario->setPlayerPos(100,100);
	//}
 //   if(IntersectRect(&temp1, &m_mario->getPlayerInfo()->mario_Rect, &m_monster->getMonster()->monster_Image[1]->getBoundingBox()) && (KEYMANAGER->isStayKeyDown(VK_LEFT)))
 //   {
 //   	m_mario->setPlayerPos(m_monster->getMonster()->monster_Image[1]->getBoundingBox().right +10,
 //   		m_mario->getPlayerInfo()->mario_Rect.left + 10 + m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth());
	//	//m_mario->setPlayerPos(100,100);
 //   }
	
	//마리오의 파이프와충돌시 뒤로 물러나는 버그 있음
	//RECT temp;
	//if (IntersectRect(&temp, &m_mario->getPlayerInfo()->mario_Rect, &rc)) /*&& (KEYMANAGER->isStayKeyDown(VK_RIGHT)*/
	//{
	//	int  i = 2;
	//
	////m_mario->setPlayerPos(100,100);
	//	
	//}
	
	//if (IntersectRect(&temp3, &m_mario->getPlayerInfo()->mario_Rect, &m_monster->getMonster()->monster_Image[1]->getBoundingBox()) && (KEYMANAGER->isStayKeyDown(VK_LEFT)))
	//{
	//	m_mario->setPlayerPos(m_obstacle->line_Of_Obstacle[0].right + 10,
	//	m_mario->getPlayerInfo()->mario_Rect.left + 10 + m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth());
	//	//m_mario->setPlayerPos(100,100);
	//}
    /*   if (IntersectRect(&temp2, &m_mario->getPlayerInfo()->mario_Rect, &m_obstacle->line_Of_Obstacle[0]) && (KEYMANAGER->isStayKeyDown(VK_RIGHT)))
    {
		m_mario->setPlayerPos((m_mario->getPlayerInfo()->mario_Rect.right - 10) - m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth(),
			m_obstacle->line_Of_Obstacle[0].left - 10);
    }*/
	
    //if(IntersectRect(&temp, &m_mario->getPlayerInfo()->mario_Rect, &m_monster->getMonster()->monster_Image[1]->getBoundingBox()) && (KEYMANAGER->isStayKeyDown(VK_RIGHT)))
    //{
    //	m_mario->setPlayerPos(m_mario->getPlayerInfo()->mario_Rect.right - m_mario->getPlayerInfo()->mario_Image[0]->getFrameWidth(),
    //		m_monster->getMonster()->monster_Image[1]->getBoundingBox().le);
    //	//m_mario->setPlayerPos(100,100);
    //}
}

