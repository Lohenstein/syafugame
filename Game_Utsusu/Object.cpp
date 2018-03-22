#include "main.h"

using namespace Input;
using namespace std;

namespace Object
{
	int		piano_handle;
	int		piano_roll[64][88];
	int		rx = 230, ry = 250;
	int		sx = -1, sy = -1;
	int		scroll = 0;
	int		click_mode = 0;
	int		l = 0, cnt = 0;
	int		prev = -1;
	int		txtfont = CreateFontToHandle(_T("MS gothic"), 18, 2, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	gui		play_sample;
	gui		play_roll;
	gui		play_out;


	void	draw_Gamescreen(void) {
		DrawBox(0,	 0, 1280, 720, 0x222222, true);
		DrawBox(0, 670, 1280, 720, 0x333333, true);
		//DrawFormatStringToHandle(0, 0, 0xFFFFFF, CreateFontToHandle(_T("MS gothic"), 18, 2, DX_FONTTYPE_ANTIALIASING_EDGE_4X4), _T("あいうえお"));
		DrawFormatString(20, 685, 0xFFFFFF, _T("左クリック：ノートを置く　左クリック長押し：ノートを移動 %d %d"), note.type, note.time);
		if (play_roll.draw_Button(15, 550, 100, 100, 0x333333, 0x444444, _T("再生"))) {
			note = { -2, 0, 0 };
		}
		if (play_out.draw_Button(15, 430, 100, 100, 0x333333, 0x444444, _T("仮書出"))) {
			out_Songdata();
		}
	}

	void	out_Songdata(void) {

		ofstream ofs;  
		ofs.open(_T("C:\\Users\\maris\\source\\repos\\syafugame\\Game_Utsusu\\data\\song.txt"), ios::out);

		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 88; j++) {
				ofs << piano_roll[i][j] << endl;
			}
		}
		ofs.close();
	}

	void	init_Pianoroll(void) {
		piano_handle = MakeScreen(1024, 88 * 20, false);
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 88; j++) {
				piano_roll[i][j] == 0;
			}
		}
	}

	void	draw_Pianoroll(void) {
		SetDrawScreen(piano_handle);

		DrawBox(0, 0, 1024, 88 * 20, 0x000000, true);

		for (int i = 0; i < 88; i++) {
			DrawLine(0, i * 20, 1024, i * 20, 0x333333);
		}
		float notesize = 1024.f / 64.f;
		for (int i = 0; i < 64; i++) {
			unsigned int line_vertical = 0x333333;
			if (i % 4 == 0)  line_vertical = 0x666666;
			if (i % 16 == 0) line_vertical = 0x999999;
			DrawLineAA(i * notesize, 0.f, i * notesize, 88.f * 20.f, line_vertical);
		}
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 88; j++) {
				if (piano_roll[i][j] != 0) {
					if (piano_roll[i][j] > 0) {
						DrawBox(i * notesize, j * 20, i * notesize + (notesize * piano_roll[i][j]), j * 20 + 20, 0xAA0000, true);
						DrawBox(i * notesize, j * 20, i * notesize + (notesize * piano_roll[i][j]), j * 20 + 20, 0xFFFFFF, false);
					}
				}
			}
		}
		place_Pianoroll();
		SetDrawScreen(DX_SCREEN_BACK);

		int mouse_w = GetMouseWheelRotVol();
		if (mouse_w > 0) scroll -= 10;
		if (mouse_w < 0) scroll += 10;

		DrawRectGraph(rx, ry, 0, scroll, 1024, 400, piano_handle, false, false);
		DrawRectGraph(rx-100, ry, 0, scroll, 100, 400, Game::roll_img, false, false);

		DrawLine(rx + (note.time * 16), ry, rx + (note.time * 16), ry + 400, 0xFF00FF);
	}

	void	place_Pianoroll(void) {
		if (mouse_x > rx && mouse_x < rx + 1024 && mouse_y > ry && mouse_y < ry + 400) {
			if (mouse_l != 0) {
				if (mouse_l == 1) {
					sx = (mouse_x - rx) / (1024 / 64);
					sy = (mouse_y - ry + scroll) / 20;
					if (piano_roll[sx][sy] != 0) {
						for (;;) {
							if (piano_roll[sx][sy] != -1) {
								break;
							}
							else {
								sx--;
								cnt++;
							}
						}
						l = piano_roll[sx][sy];
						for (int i = 0; i < l; i++) {
							piano_roll[sx + i][sy] = 0;
						}
						click_mode = 2;
					}
					else {
						note = { -1, -1, 88 - sy };
						click_mode = 1;
					}
				}
				else {
					if (click_mode == 1) {
						if ((sx * (1024 / 64)) + rx < mouse_x) {
							int newsx = (mouse_x - rx) / (1024 / 64);
							float notesize = 1024.f / 64.f;

							DrawBox(sx * notesize, sy * 20, newsx * notesize + notesize, sy * 20 + 20, 0xAA0000, true);
							DrawBox(sx * notesize, sy * 20, newsx * notesize + notesize, sy * 20 + 20, 0xFFFFFF, false);
						}
					}
					else {
						int newsx = (mouse_x - rx) / (1024 / 64);
						int newsy = (mouse_y - ry + scroll) / 20;
						float notesize = 1024.f / 64.f;
						DrawBox((newsx - cnt) * notesize, newsy * 20, ((newsx - cnt - 1) + l) * notesize + notesize, newsy * 20 + 20, 0xAA0000, true);
						DrawBox((newsx - cnt) * notesize, newsy * 20, ((newsx - cnt - 1) + l) * notesize + notesize, newsy * 20 + 20, 0xFFFFFF, false);
						if (prev != newsy) {
							note = { -1, -1, 88 - newsy };
						}
						prev = newsy;
					}
				}
			}
			else {
				if (click_mode == 1) {
					if ((sx * (1024 / 64)) + rx < mouse_x) {
						int newsx = (mouse_x - rx) / (1024 / 64);
						piano_roll[sx][sy] = 1 + (newsx - sx);
						for (int i = 0; i < newsx - sx; i++) {
							piano_roll[sx + 1 + i][sy] = -1;
						}
					}
					else {
						piano_roll[sx][sy] = 1;
					}
					click_mode = 0;
				}
				else if (click_mode == 2) {
					int newsx = (mouse_x - rx) / (1024 / 64);
					int newsy = (mouse_y - ry + scroll) / 20;
					for (int i = 0; i < l; i++) {
						piano_roll[(newsx - cnt) + i][newsy] = -1;
					}
					piano_roll[newsx - cnt][newsy] = l;
					cnt			= 0;
					l			= 0;
					prev		= -1;
					click_mode	= 0;
				}
			}
		}
	}

	bool gui::draw_Button(int mx, int my, int mw, int mh, unsigned int normal, unsigned int over, const wchar_t *str) {

		// メンバに代入
		stats = 1;
		x = mx;
		y = my;
		h = mh;
		w = mw;
		normal_color = normal;
		over_color = over;

		int draw_px = (x + (w / 2)) - GetDrawFormatStringWidth(_T("%s"), str) / 2;
		int draw_py = (y + (h / 2)) - 10;

		// 判定
		if (mouse_x > x && mouse_x < x + w && mouse_y > y && mouse_y < y + h) {
			if (mouse_l != 0) {
				DrawBox(x, y, x + w, y + h, GetColor(255, 0, 0), TRUE);
				DrawFormatString(draw_px, draw_py, GetColor(255, 255, 255),  _T("%s"), str);
				if (mouse_l == 1) return true;
			}
			DrawBox(x, y, x + w, y + h, over_color, TRUE);
		}
		else {
			DrawBox(x, y, x + w, y + h, normal_color, TRUE);
		}

		DrawFormatString(draw_px, draw_py, GetColor(255, 255, 255), _T("%s"), str);

		return false;
	}
}
