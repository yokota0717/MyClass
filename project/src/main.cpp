#include "DxLib.h"
#include "Utility/Utility.hpp"
#include "System/Input/Input.h"
#include "define.h"
#include "System/Node/Node.h"
#include "Scene/GameManager.h"
//���������[�N���m�p
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//-------------------------------------------------------------------------------------------------------------------
//���C�����[�v�̏������܂Ƃ߂�
bool ProcessLoop() {
	if (ScreenFlip() != 0) return false;
	if (ProcessMessage() != 0) return false;
	if (ClearDrawScreen() != 0) return false;
	return true;
}
//-------------------------------------------------------------------------------------------------------------------
//�������֘A���܂Ƃ߂�
void DXinit() {
	SetOutApplicationLogValidFlag(FALSE);			//���O����
	SetMainWindowText("Game");						//�E�C���h�E�^�C�g����ύX
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16);	//��ʉ𑜓x�A�F�[�x�o�b�t�@�H�ύX
	//�E�B���h�E���[�h�ύX
#if _DEBUG
	ChangeWindowMode(1);
#else
	if (MessageBox(NULL, "�t���X�N���[���ŋN�����܂����H", "�N���I�v�V����", MB_YESNO) == IDYES) {
		ChangeWindowMode(0);
	}
	else {
		ChangeWindowMode(1);
	}
#endif
	SetDrawScreen(DX_SCREEN_BACK);	//����ʐݒ�
	DxLib_Init();
}
//-------------------------------------------------------------------------------------------------------------------


int Node::uid_ = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ShowConsole();
#endif
	DXinit();

	while (ProcessLoop()) {
		game->doAll();
		if (game->kb.Down(ESCAPE)) { break; }
	};
	delete game;
	DxLib_End(); // DX���C�u�����I������
	return 0;
}