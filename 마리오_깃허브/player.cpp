#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_player._image[0] = new image;
	_player._image[0] = IMAGEMANAGER->addFrameImage("character", "images/¸¶¸®¿À.bmp", 182 * 3, 32 * 3, 7, 1, true, RGB(255, 0, 255));


	_player._image[1] = new image;
	_player._image[1] = IMAGEMANAGER->addImage("jump", "images/player_jump.bmp", 33 * 3, 40 * 3, true, RGB(255, 0, 255));

	_player.rc = RectMakeCenter(150, WINSIZEY / 2, _player._image[0]->getFrameWidth(), _player._image[0]->getFrameHeight());

	_player.isJump = false;
	_player.count = 0;
	_player.index = 0;
	_player.jump_power = 0;
	_player.gravity = 0;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_player.count++;
	if (_player.count % 10 == 0)
	{
		_player.count = 0;
		_player.index++;
		if (_player.index >= _player._image[0]->getMaxFrameX())
		{
			_player.index = 0;
		}
		_player._image[0]->setFrameX(_player.index);
	}

	keyControl();
	jump();
}

void player::render()
{
	IMAGEMANAGER->frameRender("character", getMemDC(), _player.rc.left, _player.rc.top, _player._image[0]->getFrameX(), _player._image[0]->getFrameY());

	if (_player.isJump)
	{
		IMAGEMANAGER->render("jump", getMemDC(), _player.rc.left, _player.rc.top);
	}

}

void player::jump()
{

	if (!_player.isJump)
	{
		_player.gravity = 5;

		OffsetRect(&_player.rc, 0, _player.gravity);

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_player.isJump = true;

			_player.jump_power = 10.0f;
		}
	}
	if (_player.isJump)
	{
		_player.gravity = 0.5f;
		_player.rc.top -= _player.jump_power;
		_player.rc.bottom -= _player.jump_power;
		_player.jump_power -= _player.gravity;
	}


}

void player::keyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		OffsetRect(&_player.rc, -5, 0);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		OffsetRect(&_player.rc, 5, 0);
	}
}
