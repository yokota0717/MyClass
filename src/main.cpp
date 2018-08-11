#include "DxLib.h"
#include "Console\Console.h"
#include "Input\Input.h"
#include "Object\Object.h"
#include "Actor\Game.h"
//���������[�N���m�p
#include <crtdbg.h>

//-------------------------------------------------------------------------------------------------------------------
//���C�����[�v�̏������܂Ƃ߂�
int ProcessLoop() {
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//�������֘A���܂Ƃ߂�
void DXinit() {
	SetOutApplicationLogValidFlag(FALSE);			//���O����
	SetMainWindowText("Game");						//�E�C���h�E�^�C�g����ύX
	SetGraphMode(960, 540, 16);						//��ʉ𑜓x�A�F�[�x�o�b�t�@�H�ύX
	//SetWindowSize(960, 540);						//��ʃT�C�Y�ύX
	//�E�B���h�E���[�h�ύX
	if (MessageBox(NULL, "�t���X�N���[���ŋN�����܂����H", "�N���I�v�V����", MB_YESNO) == IDYES) {
		ChangeWindowMode(0);
	}
	else {
		ChangeWindowMode(1);
	}
	SetDrawScreen(DX_SCREEN_BACK);	//����ʐݒ�
	DxLib_Init();
}
//-------------------------------------------------------------------------------------------------------------------




int GameObject::uid_ = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#if _DEBUG
	ShowConsole();
#endif
	DXinit();

	while (ProcessLoop() == 0) {
		game->doAll();
		if (game->kb.Down(ESCAPE)) { break; }
	};
	delete game;
	DxLib_End(); // DX���C�u�����I������
	_CrtDumpMemoryLeaks();	// ���̎��_�ŊJ������Ă��Ȃ��������̏��̕\��
	return 0;
}