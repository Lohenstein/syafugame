
#include "Main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// 設定
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
	SetMainWindowText("写譜屋");

	SetDrawScreen(DX_SCREEN_BACK);

	// 初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ゲーム初期化
	game_init();

	// メインループ
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) 
	{
		// ゲームメイン
		game_main();
	}

	// ゲーム終了
	game_end();
	DxLib_End();

	return 0;
}