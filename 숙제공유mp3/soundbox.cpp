#include "stdafx.h"
#include "soundbox.h"

void soundbox::delete_image()
{
	//�̹��� �����ϴ¹��
	//�迭 �Ҷ����� nullptr �� �����
	//����� ������ �ʱ�ȭ��->ó�� ������ �����
	button_Of_Music[0] = nullptr;
	button_Of_Music[1] = nullptr;
	button_Of_Music[2] = nullptr;
	button_Of_Music[3] = nullptr;

	IMAGEMANAGER->deleteImage("���");
	IMAGEMANAGER->deleteImage("����");
	IMAGEMANAGER->deleteImage("�ٽ�");
	IMAGEMANAGER->deleteImage("����");
	IMAGEMANAGER->deleteImage("����");
}
void soundbox::init_image()
{
	//���� ��ư
	IMAGEMANAGER->addImage("���", "images/���.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Play = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 100, 50, 50);
	IMAGEMANAGER->addImage("����", "images/������ư.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Stop = RectMakeCenter(WINSIZEX / 2, WINSIZEY+ 50, 50, 100);
	IMAGEMANAGER->addImage("�ٽ�", "images/�ٽý���.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Resume = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 150, 50, 50);
	IMAGEMANAGER->addImage("����", "images/�������.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Next = RectMakeCenter(WINSIZEX / 2 + 80, WINSIZEY / 2 + 100, 50, 50);
	IMAGEMANAGER->addImage("����", "images/�������.bmp", 50, 50, true, RGB(255, 0, 255));
	Button_Previous = RectMakeCenter(WINSIZEX / 2 - 80, WINSIZEY / 2 + 100, 50, 50);
	Check_Resume = false;
	Check_Play   = false;


}
void soundbox::init_sound()
{
	SOUNDMANAGER->addSound("�˷���", "sound/snow_flower.mp3", true, true);
	SOUNDMANAGER->addSound("��ȿ��", "sound/ó���̶�.mp3", true, true);
	SOUNDMANAGER->addSound("â��", "sound/METEOR.mp3", true, true);
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
	//                          play ��ư                                    //
	//=======================================================================//
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON && Check_Play == false))
	{
		if (PtInRect(&Button_Play,m_ptMouse))
		{
			Button_Stop = RectMakeCenter(WINSIZEX / 2, WINSIZEY /2 + 100, 50, 50);
			//IMAGEMANAGER->render("����", getMemDC(), Button_Play.left, Button_Play.top);
			Button_Play = RectMakeCenter(WINSIZEX / 2, WINSIZEY + 100, 50, 50);
			SOUNDMANAGER->play("â��", 1.0f);
			Check_Play = true;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON && Check_Play == true))
	{
		if (PtInRect(&Button_Stop,m_ptMouse))
		{
			SOUNDMANAGER->stop("â��");
			Check_Play = false;
			//���⿡�� �̴ϼȷ� ���ư��������� �ѹ��ۿ� ��� & �Ͻ�������ư�� �ѹ��ۿ� ����������
			init();
		}
	}  

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) && Check_Resume == false)
	{
		if (PtInRect(&Button_Resume, m_ptMouse))
		{
			SOUNDMANAGER->resume("â��");
			init();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&Button_Pause, m_ptMouse))
		{
			SOUNDMANAGER->pause("â��");
		}
	}

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&Button_Next, m_ptMouse))
	//	{
	//		SOUNDMANAGER->Next("â��");
	//	}
	//}

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&Button_Previous, m_ptMouse))
	//	{
	//		SOUNDMANAGER->stop("â��");
	//	}
	//}
}

void soundbox::render()
{
	IMAGEMANAGER->render("���", getMemDC(), Button_Play.left,Button_Play.top);
	IMAGEMANAGER->render("����", getMemDC(), Button_Stop.left,Button_Stop.top);
	IMAGEMANAGER->render("�ٽ�", getMemDC(), Button_Resume.left,Button_Resume.top);
	IMAGEMANAGER->render("����", getMemDC(), Button_Next.left,Button_Next.top);
	IMAGEMANAGER->render("����", getMemDC(), Button_Previous.left,Button_Previous.top);
}

