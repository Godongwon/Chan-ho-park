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

	//이건 해당 구조체를 통째로(반환값과 리턴값을 반드시 확인)
	tagPlayer* getPlayerInfo() { return &_player; }

	//아래는 구조체 내에 필요한 정보만
	RECT getRectPlayer() { return _player.rc; }
	//bool getJump() { return _player.isJump; }


};

