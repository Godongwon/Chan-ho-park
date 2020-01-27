#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	m_Sound_Box = new soundbox;
	m_Sound_Box ->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	m_Sound_Box->release();
	m_Sound_Box = nullptr;
}
void mainGame::update()
{
	gameNode::update();
	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&rc, m_ptMouse))
	//	{
	//		OPENFILENAME ofn;

	//		char filePathSize[1024] = "";

	//		ZeroMemory(&ofn, sizeof(OPENFILENAME));


	//		ofn.lStructSize = sizeof(OPENFILENAME);//����ü ������ ����
	//		ofn.hwndOwner = NULL;//��ȭ���� �����ڸ� ����
	//		ofn.lpstrFile = filePathSize;//�����̸� ����Ʈ�� ó�� ��Ÿ�� ���ϸ��� ����. ����ѹ��۰� �־�� �Ѵ�.
	//		ofn.nMaxFile = sizeof(filePathSize);
	//		ofn.nFilterIndex = true;//���� ���� �޺��ڽ����� ����� ������ �ε����� ����
	//		ofn.lpstrFileTitle = NULL;
	//		ofn.nMaxFileTitle = NULL;
	//		ofn.lpstrInitialDir = NULL;
	//		ofn.lpstrFilter = ("��������");//�̸�(��������)


	//		//��ȭ������ ���� ������ ����
	//		//OFN_PATHMUSTEXIST : �����ϴ� ��ο� ���ϸ� �Է�
	//		//OFN_FILEMUSTEXIST :�����ϴ� ���ϸ� �Է�
	//		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;


	//		if (GetOpenFileName(&ofn) == FALSE)return;


	//		char temp[1024];


	//		strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));
	//		char* context = NULL;
	//		char* token = strtok_s(temp, "\\", &context);

	//		while (strlen(context))
	//		{
	//			token = strtok_s(NULL, "\\", &context);
	//		}
	//		SOUNDMANAGER->addSound(token, ofn.lpstrFile, false, false);
	//	}
	//	SOUNDMANAGER->play("ü��.mp3", 1.0f);
	//}
	//SCENEMANAGER->update();
	m_Sound_Box->update();
}

void mainGame::render(/*HDC hdc*/)
{
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	//IMAGEMANAGER->render("���", getMemDC());
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	m_Sound_Box->render();
	//SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDC());
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

