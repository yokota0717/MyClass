#include "DxLib.h"
#include "./include/Wipe/Wipe.h"
#include "./include/WorldData.h"

void Wipe::Horizonal(int pic1, int pic2) {
	int i, j;
	// ���[�v
	for (i = 0; i < 17; i++)
	{	// �O���t�B�b�N�P��`�悵�܂�
		DrawGraph(0, 0, pic1, FALSE);

		// �O���t�B�b�N�Q��`�悵�܂�
		for (j = 0; j <= SCREEN_HEIGHT / 16; j++)
		{
			// �`��͈͂��w�肵�܂�
			SetDrawArea(0, j * 16, SCREEN_WIDTH, j * 16 + i);

			// �O���t�B�b�N�Q��`�悵�܂�
			DrawGraph(0, 0, pic2, FALSE);
		}

		SetDrawArea(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		// ����ʂ̓��e��\��ʂɔ��f�����܂�
		ScreenFlip();

		// ���ԑ҂�
		WaitTimer(15);
	}

	// �O���t�B�b�N�n���h�����Ƃ肩����
	//i = pic1;
	//pic1 = pic2;
	//pic2 = i;

	//// �L�[���͑҂�
	//while (!ProcessMessage() && CheckHitKeyAll()) {}
	//while (!ProcessMessage() && !CheckHitKeyAll()) {}
}
void Wipe::Vertical(int pic1, int pic2) {

}
