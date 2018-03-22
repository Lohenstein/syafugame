#include "Main.h"

namespace Menu {

	int sukia =50;
	int Mouse_X, Mouse_Y;

	int hankei = 0;
	int hankei2 = 200;
	int circle_movex1 = 1;
	int circle_movex2 = 1;
	int circle_movey1 = 1;
	int circle_movey2 = 1;

	int MaxMusic = 3;
	int kyoku = 0;

	

	void Init()
	{
		SetFontSize(64);

	}

	void Title_Updata()
	{


		GetMousePoint(&Mouse_X, &Mouse_Y);

		if ((Mouse_X <= WINDOW_SIZE_X * 0.3125 && Mouse_X >= WINDOW_SIZE_X * 0.0625) && (Mouse_Y <= WINDOW_SIZE_Y * 0.7 && Mouse_Y >= WINDOW_SIZE_Y * 0.3) && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			Music easy;
			Game::mode = Game::mode_game;
		}

		if ((Mouse_X <= WINDOW_SIZE_X * 0.625 && Mouse_X >= WINDOW_SIZE_X * 0.375) && (Mouse_Y <= WINDOW_SIZE_Y * 0.7 && Mouse_Y >= WINDOW_SIZE_Y * 0.3) && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			//Music nomal;
			//Game::mode = Game::mode_game;
		}

		if ((Mouse_X <= WINDOW_SIZE_X * 0.9375 && Mouse_X >= WINDOW_SIZE_X * 0.6875) && (Mouse_Y <= WINDOW_SIZE_Y * 0.7 && Mouse_Y >= WINDOW_SIZE_Y * 0.3) && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			//Music hard;
			//Game::mode = Game::mode_game;
		}
	}
	void Title_Draw()
	{

		if (hankei2 <= 90) { hankei2 = 200; hankei2--; }
		else if (hankei2 <= 100) {
			hankei2 -= 2.5;
		}
		else { hankei2 -= 5; }


		DrawBox(WINDOW_SIZE_X*0.0625,WINDOW_SIZE_Y*0.3, WINDOW_SIZE_X*0.3125, WINDOW_SIZE_Y*0.7, GetColor(255, 0, 0), FALSE);
		DrawBox(WINDOW_SIZE_X*0.375, WINDOW_SIZE_Y*0.3, WINDOW_SIZE_X*0.625, WINDOW_SIZE_Y*0.7, GetColor(255, 0, 0), FALSE);
		DrawBox(WINDOW_SIZE_X*0.6875, WINDOW_SIZE_Y*0.3, WINDOW_SIZE_X*0.9375, WINDOW_SIZE_Y*0.7, GetColor(255, 0, 0), FALSE);

		if ((Mouse_X <= WINDOW_SIZE_X * 0.3125 && Mouse_X >= WINDOW_SIZE_X * 0.0625) && (Mouse_Y <= WINDOW_SIZE_Y * 0.7 && Mouse_Y >= WINDOW_SIZE_Y * 0.3)) {
			DrawBox(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, GetColor(100, 100, 255), TRUE);
			DrawBox(WINDOW_SIZE_X*0.0625, WINDOW_SIZE_Y*0.3, WINDOW_SIZE_X*0.3125, WINDOW_SIZE_Y*0.7, GetColor(210, 255, 0), TRUE);
			DrawCircleAA(WINDOW_SIZE_X *0.1875, WINDOW_SIZE_Y / 2, hankei, 32, GetColor(255, 255, 255), FALSE);
			if (hankei < WINDOW_SIZE_X / 4) { hankei += 4; }
			else { hankei = 0; }
			DrawFormatString(WINDOW_SIZE_X *0.4-128, WINDOW_SIZE_Y * 0.8, GetColor(102, 0, 102), _T("メリーさんの羊"));

		}
		if ((Mouse_X <= WINDOW_SIZE_X * 0.625 && Mouse_X >= WINDOW_SIZE_X * 0.375) && (Mouse_Y <= WINDOW_SIZE_Y * 0.7 && Mouse_Y >= WINDOW_SIZE_Y * 0.3)) {
			DrawBox(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, GetColor(100, 255, 100), TRUE);
			DrawBox(WINDOW_SIZE_X*0.375, WINDOW_SIZE_Y*0.3, WINDOW_SIZE_X*0.625, WINDOW_SIZE_Y*0.7, GetColor(239, 117, 188), TRUE);
			DrawCircleAA(WINDOW_SIZE_X  / 2, WINDOW_SIZE_Y / 2, hankei, 32, GetColor(255, 255, 255), FALSE);
			if (hankei < WINDOW_SIZE_X / 4) { hankei += 4; }
			else { hankei = 0; }
			DrawFormatString(WINDOW_SIZE_X *0.4, WINDOW_SIZE_Y * 0.8, GetColor(102, 0, 102), _T("準備中"));
		}
		if ((Mouse_X <= WINDOW_SIZE_X * 0.9375 && Mouse_X >= WINDOW_SIZE_X * 0.6875) && (Mouse_Y <= WINDOW_SIZE_Y * 0.7 && Mouse_Y >= WINDOW_SIZE_Y * 0.3)) {
			DrawBox(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, GetColor(255, 100, 100), TRUE);
			DrawBox(WINDOW_SIZE_X*0.6875, WINDOW_SIZE_Y*0.3, WINDOW_SIZE_X*0.9375, WINDOW_SIZE_Y*0.7, GetColor(40, 150, 37), TRUE);
			DrawCircleAA(WINDOW_SIZE_X *0.8125, WINDOW_SIZE_Y / 2, hankei, 32, GetColor(255, 255, 255), FALSE);
			if (hankei < WINDOW_SIZE_X / 4) { hankei += 4; }
			else { hankei = 0; }
			DrawFormatString(WINDOW_SIZE_X *0.4, WINDOW_SIZE_Y * 0.8, GetColor(102, 0,102), _T("準備中"));
		}
		DrawCircleAA(0, 0, hankei2, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(WINDOW_SIZE_X, 0, hankei2, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(0, WINDOW_SIZE_Y, hankei2, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(WINDOW_SIZE_X, WINDOW_SIZE_Y, hankei2, 32, GetColor(255, 255, 255), TRUE);
		DrawFormatString(WINDOW_SIZE_X *0.4, WINDOW_SIZE_Y * 0.05, GetColor(255, 255, 255), _T("写譜屋"));

	}

	void Updata()
	{
		GetMousePoint(&Mouse_X, &Mouse_Y);

		if ((Mouse_X <= WINDOW_SIZE_X * 0.6 && Mouse_X >= WINDOW_SIZE_X * 0.4) && (Mouse_Y <= WINDOW_SIZE_Y * 0.35 && Mouse_Y >= WINDOW_SIZE_Y * 0.25) && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			Game::mode = Game::mode_game;
		}

		if ((Mouse_X <= WINDOW_SIZE_X * 0.6 && Mouse_X >= WINDOW_SIZE_X * 0.4) && (Mouse_Y <= WINDOW_SIZE_Y * 0.6 && Mouse_Y >= WINDOW_SIZE_Y * 0.5) && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			Game::mode = Game::mode_title;
			WaitTimer(1000);
		}

		if ((Mouse_X <= WINDOW_SIZE_X * 0.6 && Mouse_X >= WINDOW_SIZE_X * 0.4) && (Mouse_Y <= WINDOW_SIZE_Y * 0.85 && Mouse_Y >= WINDOW_SIZE_Y * 0.75) && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			Game::mode = Game::mode_over;
			WaitTimer(1000);
		}
	}


	void Draw()
	{

		/*DrawCircleAA(100, 100, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(400, 100, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(700, 100,50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(1000, 100,50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(1300, 100, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(0, 200, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(300, 200, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(600, 200, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(900, 200, 50, 32, GetColor(255, 255, 255), TRUE);
		DrawCircleAA(1200, 200, 50, 32, GetColor(255, 255, 255), TRUE);*/

		DrawBox(0, 0, 128 * 1, 128, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 2, 0, 128 * 3, 128, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 4, 0, 128 * 5, 128, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 6, 0, 128 * 7, 128, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 8, 0, 128 * 9, 128, GetColor(50, 0, 101), TRUE);

		DrawBox(128*1, 128, 128 * 2, 128*2, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 3, 128, 128 * 4, 128*2, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 5, 128, 128 * 6, 128*2, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 7, 128, 128 * 8, 128*2, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 9, 128, 128 * 10, 128*2, GetColor(50, 0, 101), TRUE);

		DrawBox(0, 256, 128 * 1, 384, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 2, 256, 128 * 3, 384, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 4, 256, 128 * 5, 384, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 6, 256, 128 * 7, 384, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 8, 256, 128 * 9, 384, GetColor(50, 0, 101), TRUE);

		DrawBox(128*1, 384, 128 * 2, 512, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 3, 384, 128 * 4, 512, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 5, 384, 128 * 6, 512, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 7, 384, 128 * 8, 512, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 9, 384, 128 * 10, 512, GetColor(50, 0, 101), TRUE);

		DrawBox(0, 512, 128 * 1, 640, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 2, 512, 128 * 3, 640, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 4, 512, 128 * 5, 640, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 6, 512, 128 * 7, 640, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 8, 512, 128 * 9, 640, GetColor(50, 0, 101), TRUE);

		DrawBox(128 * 1, 640, 128 * 2, 768, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 3, 640, 128 * 4, 768, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 5, 640, 128 * 6, 768, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 7, 640, 128 * 8, 768, GetColor(50, 0, 101), TRUE);
		DrawBox(128 * 9, 640, 128 * 10, 768, GetColor(50, 0, 101), TRUE);


		if ((Mouse_X <= WINDOW_SIZE_X *0.6 + 32 && Mouse_X >= WINDOW_SIZE_X * 0.4 - 32) && (Mouse_Y <= WINDOW_SIZE_Y *0.35 && Mouse_Y >= WINDOW_SIZE_Y * 0.25)) {
			DrawBox(WINDOW_SIZE_X *0.4 - 32, WINDOW_SIZE_Y *0.25, WINDOW_SIZE_X *0.6 + 32, WINDOW_SIZE_Y *0.35, GetColor(255, 0, 0), TRUE);
		
		}
		if ((Mouse_X <= WINDOW_SIZE_X * 0.6 + 32 && Mouse_X >= WINDOW_SIZE_X * 0.4 - 32) && (Mouse_Y <= WINDOW_SIZE_Y * 0.6 && Mouse_Y >= WINDOW_SIZE_Y * 0.5)) {
			DrawBox(WINDOW_SIZE_X *0.4 - 32, WINDOW_SIZE_Y *0.5, WINDOW_SIZE_X *0.6 + 32, WINDOW_SIZE_Y *0.6, GetColor(0, 255, 255), TRUE);
		}
		if ((Mouse_X <= WINDOW_SIZE_X * 0.6+32 && Mouse_X >= WINDOW_SIZE_X * 0.4 - 32) && (Mouse_Y <= WINDOW_SIZE_Y * 0.85 && Mouse_Y >= WINDOW_SIZE_Y * 0.75)) {
			DrawBox(WINDOW_SIZE_X *0.4 -32, WINDOW_SIZE_Y *0.75, WINDOW_SIZE_X *0.6 + 32, WINDOW_SIZE_Y *0.85, GetColor(255,0 , 255), TRUE);
		}
		DrawBox(WINDOW_SIZE_X *0.4-32, WINDOW_SIZE_Y *0.25, WINDOW_SIZE_X *0.6+32, WINDOW_SIZE_Y *0.35, GetColor(255, 0, 0), FALSE);
		DrawFormatString(WINDOW_SIZE_X *0.4, WINDOW_SIZE_Y *0.25, GetColor(255, 255, 255), _T(" 続ける "));

		DrawBox(WINDOW_SIZE_X *0.4-32, WINDOW_SIZE_Y *0.5, WINDOW_SIZE_X *0.6+32, WINDOW_SIZE_Y *0.6, GetColor(0, 255, 255), FALSE);
		DrawFormatString(WINDOW_SIZE_X *0.4 -32, WINDOW_SIZE_Y *0.5, GetColor(255, 255, 255), _T("タイトルへ"));

		DrawBox(WINDOW_SIZE_X *0.4-32, WINDOW_SIZE_Y *0.75, WINDOW_SIZE_X *0.6+32, WINDOW_SIZE_Y *0.85, GetColor(255, 0, 255), FALSE);
		DrawFormatString(WINDOW_SIZE_X *0.4 - 32, WINDOW_SIZE_Y *0.75 , GetColor(255, 255, 255), _T("ゲーム終了"));

		DrawFormatString(WINDOW_SIZE_X *0.4+32, WINDOW_SIZE_Y *0.05, GetColor(255, 255, 255), _T(" MENU "));

	}

}
