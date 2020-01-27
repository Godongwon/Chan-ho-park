#pragma once
#include"gameNode.h"
#include"player.h"
#include"Object.h"
#include"maincharacter.h"


class circus : public gameNode
{
	maincharacter * _maincharacter;
	player  *_player;
	Object * obj;
	bool isChange;
public:

	circus();
	~circus();

	HRESULT init();
	void update();
	void release();
	void render();

	void collision();
};

