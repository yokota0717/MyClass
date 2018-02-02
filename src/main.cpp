#include "DxLib.h"
#include "../include/Input/Input.h"
#include "../include/Figure/Vec.h"
#include "../include/Figure/Shape.h"
#include "../include/Collision/Collision.h"
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
	SetGraphMode(800, 600, 16);
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);	//��ʃT�C�Y�ύX
	ChangeWindowMode(TRUE), SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�


	int white = GetColor(255, 255, 255);
	int red = GetColor(255, 50, 50);

	Keyboard keyboard;
	Mouse mouse;

	//CircleCollider ccol(100, 100, 50);
	//OrvalCollider ocol(100, 100, 80, 40, 0);
	//Vec v1(400, 300);
	Vec v2(50, 10);
	//
	//bool hit = false;


	DINPUT_JOYSTATE input;
	int i;
	int Color;


	while (ProcessLoop() == 0) {	//���C�����[�v
		keyboard.update();
		mouse.update();
		if (keyboard.getKey(KEY_INPUT_LEFT) >= 1)
			v2.x -= 1.0f;
		if (keyboard.getKey(KEY_INPUT_RIGHT) >= 1)
			v2.x += 1.0f;
		if (keyboard.getKey(KEY_INPUT_UP) >= 1)
			v2.y -= 1.0f;
		if (keyboard.getKey(KEY_INPUT_DOWN) >= 1)
			v2.y += 1.0f;

		//DrawFormatString(0, 0, white, "%d\n%d\n%d", mouse.x, mouse.y, mouse.wheel);


		// ���͏�Ԃ��擾
		GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

		// ��ʂɍ\���̂̒��g��`��
		Color = GetColor(255, 255, 255);
		DrawFormatString(0, 0, Color, "X:%d Y:%d Z:%d",
			input.X, input.Y, input.Z);
		DrawFormatString(0, 16, Color, "Rx:%d Ry:%d Rz:%d",
			input.Rx, input.Ry, input.Rz);
		DrawFormatString(0, 32, Color, "Slider 0:%d 1:%d",
			input.Slider[0], input.Slider[1]);
		DrawFormatString(0, 48, Color, "POV 0:%d 1:%d 2:%d 3:%d",
			input.POV[0], input.POV[1],
			input.POV[2], input.POV[3]);
		DrawString(0, 64, "Button", Color);
		for (i = 0; i < 32; i++)
		{
			DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
				"%2d:%d", i, input.Buttons[i]);
		}
		//if(ccol.Collision(v))
		//	DrawCircle(ccol.col.x, ccol.col.y, ccol.col.r, red);
		//else
		//	DrawCircle(ccol.col.x, ccol.col.y, ccol.col.r, white);

		//if (ocol.Collision(v1, v2))
		//	DrawOval(ocol.col.x, ocol.col.y, ocol.col.lr, ocol.col.sr, red, true);
		//else
		//	DrawOval(ocol.col.x, ocol.col.y, ocol.col.lr, ocol.col.sr, white, true);

		//DrawLine(v1.x, v1.y, v2.x, v2.y, white);
		//DrawCircle((int)v2.x, (int)v2.y, 3, white);

		if (keyboard.getKey(KEY_INPUT_ESCAPE) == 1) break;  //Esc�L�[�������ꂽ��I��

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}