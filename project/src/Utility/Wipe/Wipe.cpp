#include "DxLib.h"
#include "Wipe.h"
#include "../../define.h"

void Wipe::Horizonal(int pic1, int pic2) {
	int i, j;
	// ループ
	for (i = 0; i < 17; i++)
	{	// グラフィック１を描画します
		DrawGraph(0, 0, pic1, FALSE);

		// グラフィック２を描画します
		for (j = 0; j <= SCREEN_HEIGHT / 16; j++)
		{
			// 描画範囲を指定します
			SetDrawArea(0, j * 16, SCREEN_WIDTH, j * 16 + i);

			// グラフィック２を描画します
			DrawGraph(0, 0, pic2, FALSE);
		}

		SetDrawArea(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		// 裏画面の内容を表画面に反映させます
		ScreenFlip();

		// 時間待ち
		WaitTimer(15);
	}

	// グラフィックハンドルをとりかえる
	//i = pic1;
	//pic1 = pic2;
	//pic2 = i;

	//// キー入力待ち
	//while (!ProcessMessage() && CheckHitKeyAll()) {}
	//while (!ProcessMessage() && !CheckHitKeyAll()) {}
}
void Wipe::Vertical(int pic1, int pic2) {

}
