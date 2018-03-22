
#include "Main.h"

namespace Game
{
	int roll_img;
	int mode = mode_title;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< ゲーム初期化 >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
	roll_img = LoadGraph(_T("data/img/piano.png"));
	Object::Init();
	Menu::Init();
}
/*------------------------------------------------------------------------------*
| <<< ゲームメイン >>>
*------------------------------------------------------------------------------*/
void	game_main(void)
{

	// 処理
	switch (mode)
	{
	case mode_title:
		Menu::Updata();
		/*if ((GetMouseInput &&MOUSE_INPUT_LEFT) != 1)
		{
			mode = mode_game;
		}*/
		break;
	case mode_game:
		Input::mouse_Input();
		break;
	case mode_over:
		break;
	}

	// 描画
	switch (mode)
	{
	case mode_title:
		Menu::Draw();
		break;
	case mode_game:
		Object::draw_Gamescreen();
		Object::draw_Pianoroll();
		Object::Draw();
		break;
	case mode_over:
		break;
	}
}

/*------------------------------------------------------------------------------*
| <<< ゲーム終了 >>>
*------------------------------------------------------------------------------*/
void	game_end(void)
{
}