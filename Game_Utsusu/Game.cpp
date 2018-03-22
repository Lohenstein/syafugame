
#include "Main.h"

namespace Game
{
	int mode = mode_title;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< ÉQÅ[ÉÄèâä˙âª >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
	Menu::Init();
}
/*------------------------------------------------------------------------------*
| <<< ÉQÅ[ÉÄÉÅÉCÉì >>>
*------------------------------------------------------------------------------*/
void	game_main(void)
{

	// èàóù
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

	// ï`âÊ
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
| <<< ÉQÅ[ÉÄèIóπ >>>
*------------------------------------------------------------------------------*/
void	game_end(void)
{
}