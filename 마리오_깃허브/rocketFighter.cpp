#include "stdafx.h"
#include "rocketFighter.h"


rocketFighter::rocketFighter()
{
}


rocketFighter::~rocketFighter()
{
}

HRESULT rocketFighter::init()
{
	IMAGEMANAGER->addImage("배경화면", "images/사나1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "images/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "images/ufo.bmp", 530, 32, 10, 1, true, RGB(255, 0, 255));
	_rocket = new rocket;
	_rocket->init();


	_enemyManager = new enemyManager;
	_enemyManager->init();


	_rocket->setEnemyMemoryLink(_enemyManager);
	_enemyManager->setRocketMemoryLink(_rocket);

	return S_OK;
}

void rocketFighter::release()
{
	SAFE_DELETE(_rocket);
	SAFE_DELETE(_enemyManager);
}

void rocketFighter::update()
{
	_rocket->update();
	_enemyManager->update();
}

void rocketFighter::render()
{
	IMAGEMANAGER->render("배경화면", getMemDC());
	_rocket->render();
	_enemyManager->render();
}
