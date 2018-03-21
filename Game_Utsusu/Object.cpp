#include "main.h"

using namespace Input;

namespace Object
{
	int		piano_handle;
	int		piano_roll[64][88];
	int		rx = 0, ry = 0;
	int		scroll = 0;

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

		for (int i = 0; i < 88; i++) {
			DrawLine(0, i * 20, 1024, i * 20, 0x333333);
		}

		float notesize = 1024.f / 64.f;
		for (int i = 0; i < 64; i++) {
			unsigned int line_vertical = 0x333333;
			if (i % 4 == 0)  line_vertical = 0x666666;
			if (i % 16 == 0) line_vertical = 0x999999;
			DrawLineAA(i * notesize, 0.f, i * notesize, 88.f * 20.f, line_vertical);
			for (int j = 0; j < 88; j++) {
				if (piano_roll[i][j] != 0) {
					DrawBox(i * notesize, j * 20, i * notesize + notesize, j * 20 + 20, 0xAA0000, true);
					DrawBox(i * notesize, j * 20, i * notesize + notesize, j * 20 + 20, 0xFFFFFF, false);
				}
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);

		DrawRectGraph(0, 0, 0, scroll, 1024, 400, piano_handle, false, false);
		place_Pianoroll();
	}

	void	place_Pianoroll(void) {
		if (mouse_x > rx && mouse_x < rx + 1024 && mouse_y > ry && mouse_y < ry + 400) {
			if (mouse_l != 0) {
				int sx = -1, sy = -1;
				if (mouse_l == 1) {
					sx = (mouse_x - rx) / (1024 / 64);
					sy = (mouse_y - ry - scroll) / 20;
					piano_roll[sx][sy] = 1;
					//vstPlugin.sendMidiNote(0, 12 + sy, true, 100);
				}
				else {

				}
			}
		}
	}
}
