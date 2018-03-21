
#include "Main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// �ݒ�
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
	SetMainWindowText("�ʕ���");

	SetDrawScreen(DX_SCREEN_BACK);

	// ������
	if (DxLib_Init() == -1) {
		return -1;
	}

	// �Q�[��������
	game_init();

	// ���C�����[�v
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) 
	{
		// �Q�[�����C��
		game_main();
	}

	// �Q�[���I��
	game_end();
	DxLib_End();

	return 0;
}