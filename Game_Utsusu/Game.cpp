
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
	Object::Init();
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
		Menu::Updata();
		/*if ((GetMouseInput &&MOUSE_INPUT_LEFT) != 1)
		{
			mode = mode_game;
		}*/
		break;
	case mode_game:
	
		break;
	case mode_over:
		break;
	}

	// ï`âÊ
	switch (mode)
	{
	case mode_title:
		Menu::Draw();
		break;
	case mode_game:

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