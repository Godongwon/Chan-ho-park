#pragma once
#include"gameNode.h"

struct tagFireRing
{
	RECT rc[2];
	image* image[2];
	RECT collisionRC;
};

class Object : public gameNode
{
private:

	RECT ground;

private:

	tagFireRing fireRing;

public:
	Object();
	~Object();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT getFirering_Rect() { return fireRing.collisionRC; }
	RECT getRect_ground() { return ground; }
	tagFireRing* getFireRing() { return &fireRing; }

public:

	void fireMove();

};

