#include "stdafx.h"
#include "soundbox.h"

void soundbox::delete_image()
{
	//이미지 해제하는방법
	//배열 할때에는 nullptr 로 지운다
	//지우는 순서는 초기화끝->처음 순으로 지운다
	button_Of_Music[0] = nullptr;
	button_Of_Music[1] = nullptr;
	button_Of_Music[2] = nullptr;
	button_Of_Music[3] = nullptr;

	IMAGEMANAGER->deleteImage("재생");
	IMAGEMANAGER->deleteImage("정지");
	IMAGEMANAGER->deleteImage("다시");
	IMAGEMANAGER->deleteImage("이전");
	IMAGEMANAGER->deleteImage("다음");
}
void soundbox::init_image()
{
	//음악 버튼
	IMAGEMANAGER->addImage("재생", "images/재생.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Play = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 100, 50, 50);
	IMAGEMANAGER->addImage("정지", "images/정지버튼.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Stop = RectMakeCenter(WINSIZEX / 2, WINSIZEY+ 50, 50, 100);
	IMAGEMANAGER->addImage("다시", "images/다시시작.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Resume = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 150, 50, 50);
	IMAGEMANAGER->addImage("다음", "images/다음재생.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Next = RectMakeCenter(WINSIZEX / 2 + 80, WINSIZEY / 2 + 100, 50, 50);
	IMAGEMANAGER->addImage("이전", "images/이전재생.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Previous = RectMakeCenter(WINSIZEX / 2 - 80, WINSIZEY / 2 + 100, 50, 50);
	Check_Resume = false;
	Check_Play   = false;


}
void soundbox::init_sound()
{
	SOUNDMANAGER->addSound("알러뷰", "sound/snow_flower.mp3", true, true);
	SOUNDMANAGER->addSound("정효빈", "sound/처음이라서.mp3", true, true);
	SOUNDMANAGER->addSound("창모", "sound/METEOR.mp3", true, true);
}
HRESULT soundbox::init()
{
	init_image();
	init_sound();
	return S_OK;
}

void soundbox::release()
{

	delete_image();
}

void soundbox::update()
{
	//=======================================================================//
	//                          play 버튼                                    //
	//=======================================================================//
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON && Check_Play == false))
	{
		if (PtInRect(&Button_Play,m_ptMouse))
		{
			Button_Stop = RectMakeCenter(WINSIZEX / 2, WINSIZEY /2 + 100, 50, 50);
			//IMAGEMANAGER->render("정지", getMemDC(), Button_Play.left, Button_Play.top);
			Button_Play = RectMakeCenter(WINSIZEX / 2, WINSIZEY + 100, 50, 50);
			SOUNDMANAGER->play("창모", 1.0f);
			Check_Play = true;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON && Check_Play == true))
	{
		if (PtInRect(&Button_Stop,m_ptMouse))
		{
			SOUNDMANAGER->stop("창모");
			Check_Play = false;
			//여기에서 이니셜로 돌아가지않으면 한번밖에 재생 & 일시정지버튼이 한번밖에 먹히지않음
			init();
		}
	}  

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) && Check_Resume == false)
	{
		if (PtInRect(&Button_Resume, m_ptMouse))
		{
			SOUNDMANAGER->resume("창모");
			init();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&Button_Pause, m_ptMouse))
		{
			SOUNDMANAGER->pause("창모");
		}
	}

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&Button_Next, m_ptMouse))
	//	{
	//		SOUNDMANAGER->Next("창모");
	//	}
	//}

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&Button_Previous, m_ptMouse))
	//	{
	//		SOUNDMANAGER->stop("창모");
	//	}
	//}
}

void soundbox::render()
{
	IMAGEMANAGER->render("재생", getMemDC(), Button_Play.left,Button_Play.top);
	IMAGEMANAGER->render("정지", getMemDC(), Button_Stop.left,Button_Stop.top);
	IMAGEMANAGER->render("다시", getMemDC(), Button_Resume.left,Button_Resume.top);
	IMAGEMANAGER->render("다음", getMemDC(), Button_Next.left,Button_Next.top);
	IMAGEMANAGER->render("이전", getMemDC(), Button_Previous.left,Button_Previous.top);
}

