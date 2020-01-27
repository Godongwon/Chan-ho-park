#include "stdafx.h"
#include "circus.h"
#include"Object.h"
#include"player.h"
#include"maincharacter.h"



circus::circus()
{
}


circus::~circus()
{
}


HRESULT circus::init()
{
	

	//IMAGEMANAGER->addImage("서커스배경화면", "images/circus_bgimage.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));


	//_player = new player;
	//_player->init();
	
	_maincharacter = new maincharacter;
	_maincharacter->init();


	obj = new Object;
	obj->init();


	isChange = false;
return S_OK;
}

void circus::release()
{
	SAFE_DELETE(_player);
	SAFE_DELETE(obj);
}

void circus::update()
{

	if (isChange == false)
	{
		//_player->update();
		_maincharacter->update();
		obj->update();


	}

	
	
}

void circus::render()
{
	IMAGEMANAGER->loopRender("서커스배경화면", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), 0, 0);

	//_player->render();
	_maincharacter->render();
	obj->render();
}

void circus::collision()
{
	RECT rc;
	if (IntersectRect(&rc, &_player->getRectPlayer(), &obj->getRect_ground()))
	{
		_player->getPlayerInfo()->isJump = false;
		_player->getPlayerInfo()->rc.bottom = obj->getRect_ground().top;
		//_player->getRectPlayer().bottom = ;
		_player->getPlayerInfo()->rc.top = _player->getPlayerInfo()->rc.bottom - _player->getPlayerInfo()->_image[0]->getFrameHeight();
	}
	if (IntersectRect(&rc, &_player->getPlayerInfo()->rc, &obj->getFireRing()->collisionRC))
	{
		//this->init();
		isChange = true;
		SCENEMANAGER->changeScene("로켓");
	}


}
