#include "DxLib.h"
#include "../include/Input/keyboard.h"
#include "../Figure/Vec.h"
#include <string>

//-------------------------------------------------------------------------------------------------------------------
//メインループの処理をまとめる
int ProcessLoop() {
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//ウィンドウサイズ
const int	SCREEN_WIDTH = 800,
			SCREEN_HEIGHT = 600;
//-------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------
//エントリーポイント
//-------------------------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetOutApplicationLogValidFlag(FALSE);		//ログ消し
	SetMainWindowText("Test");					//ウインドウタイトルを変更
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);	//画面サイズ変更
	ChangeWindowMode(TRUE), SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定


	int white = GetColor(255, 255, 255);


	while (ProcessLoop() == 0) {	//メインループ
		Keyboard_Update();



		if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1) break;  //Escキーが押されたら終了

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}