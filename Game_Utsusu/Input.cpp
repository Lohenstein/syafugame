#include "Main.h"

namespace Input
{
	int mouse_x;
	int mouse_y;
	int mouse_r;
	int mouse_l;

	void mouse_Input(void) {
		// ƒ}ƒEƒX‚ðŽæ“¾
		GetMousePoint(&mouse_x, &mouse_y);

		if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			if (mouse_l == 0) mouse_l = 1;
			else if (mouse_l == 1) mouse_l = 2;
		}
		else mouse_l = 0;

		if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
			if (mouse_r == 0) mouse_r = 1;
			else if (mouse_r == 1) mouse_r = 2;
		}
		else mouse_r = 0;
	}
}