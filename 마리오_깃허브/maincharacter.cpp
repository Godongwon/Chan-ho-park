#include"stdafx.h"
#include"maincharacter.h"
maincharacter::maincharacter()
{
}

maincharacter::~maincharacter()
{
}

HRESULT maincharacter::init()
{
	//IMAGEMANAGER->addImage("배경화면", "images/32/배경.bmp", 10240, 768, true, RGB(255, 0, 255));


	_mario.mario_Image[0] = IMAGEMANAGER->addFrameImage("걷기", "images/마리오_걷기.bmp", 48*4, 64*4, 3, 2, true, RGB(255, 0, 255));
	_mario.mario_Image[1] = IMAGEMANAGER->addFrameImage("점프", "images/점프.bmp", 32*4, 96*4, 2, 3, true, RGB(255, 0, 255));
	

	
	_mario.mario_Rect = RectMakeCenter(WINSIZEX / 2-400, WINSIZEY / 2, _mario.mario_Image[0]->getFrameWidth(), _mario.mario_Image[0]->getFrameHeight());
	ground = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 260, WINSIZEX, 50);

	
	_monster = new monster;
	_monster->init();

	_mario.mario_direction = MARIO_IDLE;
	_mario.isLeft = false;
	_mario.gravity = 0;
	_mario.jump_power = 0;
	_mario.isJump = false;
	check = false;
	isLeftArrow_keyDown = false;
	check_Collision = false;
	return S_OK;
}

void maincharacter::release()
{
}
void maincharacter::update()
{
	
	
	KeyControl();
	frame(_mario.mario_direction);
	//_monster->update();


}
void maincharacter::KeyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)&&_mario.mario_Rect.left>0)
	{
		_mario.mario_direction = MARIO_LEFT_MOVE;
		
		isLeftArrow_keyDown = true;

		if (_mario.mario_Rect.left >= WINSIZEX / 2)
		{
			_mario.mario_Rect.right -= 5;
			_mario.mario_Rect.left -= 5;
		}
		else if (_camera < 0)
		{
		
			_camera += 5.0f;
			_monster->LeftCamera();
		}
		else
		{
			_mario.mario_Rect.right -= 5;
			_mario.mario_Rect.left -= 5;
		}
	}
	
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && _mario.mario_direction == MARIO_LEFT_MOVE)
	{
		_mario.isLeft = true;
		_mario.mario_direction = MARIO_IDLE;
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)&&_mario.mario_Rect.right<WINSIZEX)
	{
		
		isLeftArrow_keyDown = false;
		_mario.mario_direction = MARIO_RIGHT_MOVE;
	

		if (_mario.mario_Rect.right <= WINSIZEX / 2)
		{
			_mario.mario_Rect.right += 5;
			_mario.mario_Rect.left += 5;
			
		}
		else if (_camera > -9210)
		{
			_camera -= 5.0f;
			_monster->RightCamera();

		}
		else
		{
			_mario.mario_Rect.right += 5;
			_mario.mario_Rect.left += 5;
		}
	}
	
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && _mario.mario_direction == MARIO_RIGHT_MOVE)
	{
		_mario.isLeft = false;
		_mario.mario_direction = MARIO_IDLE;
	}
	if (!_mario.isJump)
	{
		_mario.gravity = 6.0f;
		_mario.mario_Rect.bottom += _mario.gravity;
		_mario.mario_Rect.top += _mario.gravity;

	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && (_mario.isJump == false))
	{
		_mario.jump_power = 20.0f;
		_mario.isJump = true;
	}
	if (_mario.isJump == true)
	{
		if (isLeftArrow_keyDown)_mario.isLeft = true;
		else _mario.isLeft = false;
		_mario.mario_direction = MARIO_JUMP;
		_mario.gravity = 0.7f;
		_mario.mario_Rect.bottom -= _mario.jump_power;
		_mario.mario_Rect.top -= _mario.jump_power;
		_mario.jump_power -= _mario.gravity;
	}

	RECT temp;
	if (IntersectRect(&temp, &_mario.mario_Rect, &ground))
	{
		if (_mario.isJump)_mario.mario_direction = MARIO_IDLE;
		_mario.isJump = false;


		_mario.mario_Rect.bottom = ground.top;
		_mario.mario_Rect.top = _mario.mario_Rect.bottom - _mario.mario_Image[0]->getFrameHeight();
	}
}
void maincharacter::render()
{
	//IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	//_monster->render();
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _mario.mario_Rect.left, _mario.mario_Rect.top, _mario.mario_Rect.right, _mario.mario_Rect.bottom);
		Rectangle(getMemDC(), ground.left, ground.top, ground.right, ground.bottom);
	}
	
	
	switch (_mario.mario_direction)
	{
	case MARIO_LEFT_MOVE:
	case MARIO_RIGHT_MOVE:
	case MARIO_IDLE:
		IMAGEMANAGER->frameRender("걷기", getMemDC(), _mario.mario_Rect.left, _mario.mario_Rect.top, _mario.mario_Image[0]->getFrameX(), _mario.mario_Image[0]->getFrameY());
		break;
	case MARIO_JUMP:
		IMAGEMANAGER->frameRender("점프", getMemDC(), _mario.mario_Rect.left, _mario.mario_Rect.top, _mario.mario_Image[1]->getFrameX(), _mario.mario_Image[1]->getFrameY());
		break;

	}
}
void maincharacter::frame(MARIODIRECTION mario_direction)
{


	switch (mario_direction)
	{
	case MARIO_LEFT_MOVE:
		_mario.mario_Image[0]->setFrameY(0);
		_mario.count++;
		if (_mario.count % 5 == 0)
		{
			_mario.count = 0;
			_mario.index++;
			if (_mario.index >= _mario.mario_Image[0]->getMaxFrameX() + 1)
			{
				_mario.index = 0;
			}
			_mario.mario_Image[0]->setFrameX(_mario.index);
		}
		break;
	case MARIO_RIGHT_MOVE:
		_mario.count++;
		_mario.mario_Image[0]->setFrameY(1);
		if (_mario.count % 5 == 0)
		{
			_mario.count = 0;
			_mario.index--;
			if (_mario.index < _mario.mario_Image[0]->getMaxFrameX() - 2)
			{
				_mario.index = 2;
			}
			_mario.mario_Image[0]->setFrameX(_mario.index);
		}
		break;
	case MARIO_IDLE:
		if (_mario.isLeft)
		{
			_mario.mario_Image[0]->setFrameY(0);
			_mario.mario_Image[0]->setFrameX(0);
		}
		else
		{
			_mario.mario_Image[0]->setFrameY(1);
			_mario.mario_Image[0]->setFrameX(2);
		}
		break;
	case MARIO_JUMP:
		if (_mario.isLeft)
		{
			_mario.mario_Image[1]->setFrameY(0);
			_mario.mario_Image[1]->setFrameX(1);
		}
		else
		{
			_mario.mario_Image[1]->setFrameY(1);
			_mario.mario_Image[1]->setFrameX(0);
		
		}
		break;
	}

}

