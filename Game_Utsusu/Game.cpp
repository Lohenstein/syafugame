
#include "Main.h"

namespace Game
{
	int mode = mode_title;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< ゲーム初期化 >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
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
		Menu::Title_Updata();
		break;
	case mode_game:
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			mode = mode_menu;
		}
		break;

	case mode_menu:
		Menu::Updata();
		break;
	case mode_over:
		break;
	}

	// 描画
	switch (mode)
	{
	case mode_title:
		Menu::Title_Draw();
		break;
	case mode_game:

		break;
	case mode_menu:
		Menu::Draw();
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