
#include "Main.h"

namespace Game
{
	int mode = mode_game;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< ゲーム初期化 >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
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
		break;
	case mode_game:
		Object::draw_Pianoroll();
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