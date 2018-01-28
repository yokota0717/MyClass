#include "DxLib.h"
#include "../include/Input/keyboard.h"
#include "../Figure/Vec.h"
#include "../Figure/Shape.h"
#include "../Collision/Collision.h"
#include <string>

//#define PI 3.14159265358979323846264338327950288f

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
	SetGraphMode(800, 600, 16);
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);	//��ʃT�C�Y�ύX
	ChangeWindowMode(TRUE), SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�


	int white = GetColor(255, 255, 255);
	int red = GetColor(255, 50, 50);

	CircleCollider ccol(100, 100, 50);
	OrvalCollider ocol(100, 100, 80, 40, 0);
	Vec v1(400, 300);
	Vec v2(50, 10);
	
	bool hit = false;

	while (ProcessLoop() == 0) {	//���C�����[�v
		Keyboard_Update();
		if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
			v2.x -= 1.0f;
		if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
			v2.x += 1.0f;
		if (Keyboard_Get(KEY_INPUT_UP) >= 1)
			v2.y -= 1.0f;
		if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)
			v2.y += 1.0f;

		

		//if(ccol.Collision(v))
		//	DrawCircle(ccol.col.x, ccol.col.y, ccol.col.r, red);
		//else
		//	DrawCircle(ccol.col.x, ccol.col.y, ccol.col.r, white);

		if (ocol.Collision(v1, v2))
			DrawOval(ocol.col.x, ocol.col.y, ocol.col.lr, ocol.col.sr, red, true);
		else
			DrawOval(ocol.col.x, ocol.col.y, ocol.col.lr, ocol.col.sr, white, true);

		DrawLine(v1.x, v1.y, v2.x, v2.y, white);
		//DrawCircle(v.x, v.y, 1, white);

		if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1) break;  //Esc�L�[�������ꂽ��I��

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}