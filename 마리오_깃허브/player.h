#pragma once
#include"gameNode.h"

struct tagPlayer
{
	image* _image[3];
	RECT rc;

	float gravity;
	float jump_power;

	int count;
	int index;
	bool isJump;
};
enum PLAYERSTATE
{
	PLAYER_MOVE,
	PLAYER_NOT_MOVE,
	PLAYER_DIE,
};
class player : public gameNode
{
private:

	tagPlayer _player;

public:
	player();
	~player();


	HRESULT init();
	void release();
	void update();
	void render();

	void jump();
	void keyControl();

	//�̰� �ش� ����ü�� ��°��(��ȯ���� ���ϰ��� �ݵ�� Ȯ��)
	tagPlayer* getPlayerInfo() { return &_player; }

	//�Ʒ��� ����ü ���� �ʿ��� ������
	RECT getRectPlayer() { return _player.rc; }
	//bool getJump() { return _player.isJump; }


};

