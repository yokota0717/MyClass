#include "DxLib.h"
#include "../include/Input/keyboard.h"
#include "../Figure/Vec.h"
#include <string>

//-------------------------------------------------------------------------------------------------------------------
//���C�����[�v�̏������܂Ƃ߂�
int ProcessLoop() {
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//�E�B���h�E�T�C�Y
const int	SCREEN_WIDTH = 800,
			SCREEN_HEIGHT = 600;
//-------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------
//�G���g���[�|�C���g
//-------------------------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetOutApplicationLogValidFlag(FALSE);		//���O����
	SetMainWindowText("Test");					//�E�C���h�E�^�C�g����ύX
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);	//��ʃT�C�Y�ύX
	ChangeWindowMode(TRUE), SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�


	int white = GetColor(255, 255, 255);


	while (ProcessLoop() == 0) {	//���C�����[�v
		Keyboard_Update();



		if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1) break;  //Esc�L�[�������ꂽ��I��

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}