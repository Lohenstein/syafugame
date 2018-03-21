#include "Main.h"

namespace Menu {

	class Box {
	public:
		int box_x1 = WINDOW_SIZE_Y / 2 ;
		int box_y1 = WINDOW_SIZE_Y / 2;
		int box_x2 = WINDOW_SIZE_Y * 0.6;
		int box_y2 = WINDOW_SIZE_Y *0.6;
		int basyo = 0;
	};

	int sukia =50;
	int Mouse_X, Mouse_Y;
	Box box[4];


	void Init()
	{
		box[1].box_x1 += sukia * 2;
		box[1].box_x2 += sukia * 2;
		box[2].box_x1 += sukia * 4;
		box[2].box_x2 += sukia * 4;
		box[3].box_x1 += sukia * 6;
		box[3].box_x2 += sukia * 6;
	}

	void Updata()
	{
		/*キーボード操作の場合
		//メニューの移動処理
		if (CheckHitKey(KEY_INPUT_UP) == 1 && genzaiti != 0) {
			idoukyori -= 50;
			genzaiti--;
			WaitTimer(1000);
		}
		else {
			//ダメな効果音
			WaitTimer(1000);
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && genzaiti != 4) {
			idoukyori += 50;
			genzaiti++;
			WaitTimer(1000);
		}
		else {
			//ダメな効果音
			WaitTimer(1000);
		}
	}
	*/
		GetMousePoint(&Mouse_X, &Mouse_Y);

		if (Mouse_X <= box[0].box_x2 && Mouse_X >= box[0].box_x1) {
			if (Mouse_Y <= box[0].box_y2 && Mouse_Y >= box[0].box_y1) {
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
					Game::mode  mode_game;
				}
			}
		}

	}
	void Draw()
	{

		//DrawBox(sentaku_x1 , sentaku_y1 + idoukyori, sentaku_x2, sentaku_y2 + idoukyori, GetColor(255, 0, 0), FALSE);

		

		DrawBox(box[0].box_x1, box[0].box_y1, box[0].box_x2, box[0].box_y2, GetColor(255, 0, 0), FALSE);
		DrawBox(box[1].box_x1, box[1].box_y1, box[1].box_x2, box[1].box_y2, GetColor(255, 0, 0), FALSE);
		DrawBox(box[2].box_x1, box[2].box_y1, box[2].box_x2, box[2].box_y2, GetColor(255, 0, 0), FALSE);
		DrawBox(box[3].box_x1, box[3].box_y1, box[3].box_x2, box[3].box_y2, GetColor(255, 0, 0), FALSE);

	}
}