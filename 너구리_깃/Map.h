#pragma once
#include "gameNode.h"
class Map : public gameNode
{
private:
	image * _img;
public:
	Map();
	~Map();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

};