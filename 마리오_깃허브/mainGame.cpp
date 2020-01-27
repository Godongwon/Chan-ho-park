#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	//SCENEMANAGER->addScene("scene1", new scene1);
	////SCENEMANAGER->addScene("scene2", new scene2);
	//SCENEMANAGER->addScene("로켓", new rocketFighter);
	//
	//
	//SCENEMANAGER->addScene("서커스", new circus);
	//
	//SCENEMANAGER->changeScene("서커스");
	
	


	/*m_monster = new monster;
   m_monster->init();*/

   m_map = new Map;
   m_map->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	
}
void mainGame::update()
{
	gameNode::update();
	
	
	//m_monster->update();
	m_map->update();
	//SCENEMANAGER->update();
}

void mainGame::render(/*HDC hdc*/)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	m_map->render();
	//m_monster->render();
	//SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

