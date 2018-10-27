#pragma once
#include "DxLib.h"
#include "../../define.h"

class Wipe {
public:
	Wipe() :
		saveHandle(MakeGraph(SCREEN_WIDTH, SCREEN_HEIGHT))
	{};

	void Horizonal(int pic1,int pic2);
	void Vertical(int pic1, int pic2);


private:
	int saveHandle;		//�V�[���ڍs���̑O�V�[���X�N�V���ꎞ�ۊǗp
};