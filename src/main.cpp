#include "DxLib.h"
#include "Console\Console.h"
#include "Input\Input.h"
#include "Object\Object.h"
#include "Actor\Game.h"
//メモリリーク検知用
#include <crtdbg.h>

//-------------------------------------------------------------------------------------------------------------------
//メインループの処理をまとめる
int ProcessLoop() {
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//初期化関連をまとめる
void DXinit() {
	SetOutApplicationLogValidFlag(FALSE);			//ログ消し
	SetMainWindowText("Game");						//ウインドウタイトルを変更
	SetGraphMode(960, 540, 16);						//画面解像度、色深度バッファ？変更
	//SetWindowSize(960, 540);						//画面サイズ変更
	//ウィンドウモード変更
	if (MessageBox(NULL, "フルスクリーンで起動しますか？", "起動オプション", MB_YESNO) == IDYES) {
		ChangeWindowMode(0);
	}
	else {
		ChangeWindowMode(1);
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面設定
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
	DxLib_End(); // DXライブラリ終了処理
	_CrtDumpMemoryLeaks();	// この時点で開放されていないメモリの情報の表示
	return 0;
}