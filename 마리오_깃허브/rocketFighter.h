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

	 HRESULT init();	//�ʱ�ȭ
	 void release();//����
	 void update();//�����ϴ°�
	 void render(/*HDC hdc*/);//�׸��°�
};

