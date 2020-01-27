#pragma once
#include"gameNode.h"
#include"rocket.h"
#include"enemyManager.h"
class rocketFighter : public gameNode
{
private:

	rocket * _rocket;
	enemyManager* _enemyManager;
public:
	rocketFighter();
	~rocketFighter();

	 HRESULT init();	//초기화
	 void release();//해제
	 void update();//연산하는곳
	 void render(/*HDC hdc*/);//그리는곳
};

