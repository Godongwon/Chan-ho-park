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


	//		ofn.lStructSize = sizeof(OPENFILENAME);//구조체 사이즈 지정
	//		ofn.hwndOwner = NULL;//대화상자 소유자를 지정
	//		ofn.lpstrFile = filePathSize;//파일이름 에디트에 처음 나타낼 파일명을 지정. 충분한버퍼가 있어야 한다.
	//		ofn.nMaxFile = sizeof(filePathSize);
	//		ofn.nFilterIndex = true;//파일 형식 콤보박스에서 사용할 필터의 인덱스를 지정
	//		ofn.lpstrFileTitle = NULL;
	//		ofn.nMaxFileTitle = NULL;
	//		ofn.lpstrInitialDir = NULL;
	//		ofn.lpstrFilter = ("음악파일");//이름(파일형식)


	//		//대화상자의 모양과 동작을 지정
	//		//OFN_PATHMUSTEXIST : 존재하는 경로와 파일만 입력
	//		//OFN_FILEMUSTEXIST :존재하는 파일만 입력
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
	//	SOUNDMANAGER->play("체리.mp3", 1.0f);
	//}
	//SCENEMANAGER->update();
	m_Sound_Box->update();
}

void mainGame::render(/*HDC hdc*/)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	//IMAGEMANAGER->render("배경", getMemDC());
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	m_Sound_Box->render();
	//SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDC());
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

