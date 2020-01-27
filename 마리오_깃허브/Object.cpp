#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}
Object::~Object()
{
}

HRESULT Object::init()
{

	fireRing.image[0] = IMAGEMANAGER->addImage("firering", "images/Big_firering1-1.bmp", 12 * 3, 80 * 3, true, RGB(255, 0, 255));
	fireRing.image[1] = IMAGEMANAGER->addImage("firering1", "images/Big_firering1-2.bmp", 12 * 3, 80 * 3, true, RGB(255, 0, 255));


	fireRing.rc[0] = RectMakeCenter(WINSIZEX + 200, WINSIZEY / 2, fireRing.image[0]->getWidth(), fireRing.image[0]->getHeight());
	fireRing.rc[1] = RectMakeCenter(WINSIZEX + 230, WINSIZEY / 2, fireRing.image[1]->getWidth(), fireRing.image[1]->getHeight());

	fireRing.collisionRC = RectMakeCenter(WINSIZEX + 215, WINSIZEY / 2 + 120, 70, 30);



	ground = RectMakeCenter(WINSIZEX / 2, WINSIZEY, WINSIZEX, 100);
	return S_OK;
}

void Object::release()
{
}

void Object::update()
{
	fireMove();

}

void Object::render()
{

	IMAGEMANAGER->render("firering", getMemDC(), fireRing.rc[0].left, fireRing.rc[0].top);
	IMAGEMANAGER->render("firering1", getMemDC(), fireRing.rc[1].left, fireRing.rc[1].top);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), ground.left, ground.top, ground.right, ground.bottom);
		Rectangle(getMemDC(), fireRing.rc[0].left, fireRing.rc[0].top, fireRing.rc[0].right, fireRing.rc[0].bottom);
		Rectangle(getMemDC(), fireRing.rc[1].left, fireRing.rc[1].top, fireRing.rc[1].right, fireRing.rc[1].bottom);
	}

	Rectangle(getMemDC(), fireRing.collisionRC.left, fireRing.collisionRC.top, fireRing.collisionRC.right, fireRing.collisionRC.bottom);
}

void Object::fireMove()
{


	OffsetRect(&fireRing.collisionRC, -3, 0);
	for (int i = 0; i < 2; i++)
	{
		OffsetRect(&fireRing.rc[i], -3, 0);
	}
	if (fireRing.rc[1].right < 0)
	{
		fireRing.rc[0] = RectMakeCenter(WINSIZEX + 200, WINSIZEY / 2, fireRing.image[0]->getWidth(), fireRing.image[0]->getHeight());
		fireRing.rc[1] = RectMakeCenter(WINSIZEX + 230, WINSIZEY / 2, fireRing.image[1]->getWidth(), fireRing.image[1]->getHeight());
		fireRing.collisionRC = RectMakeCenter(WINSIZEX + 215, WINSIZEY / 2 + 120, 70, 30);
	}
}

