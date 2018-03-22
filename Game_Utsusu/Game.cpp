
#include "Main.h"

namespace Game
{
	int mode = mode_game;
	int roll_img;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< ÉQÅ[ÉÄèâä˙âª >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
	roll_img = LoadGraph(_T("data/img/piano.png"));
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
		break;
	case mode_game:
		Input::mouse_Input();
		break;
	case mode_over:
		break;
	}

	// ï`âÊ
	switch (mode)
	{
	case mode_title:
		break;
	case mode_game:
		Object::draw_Gamescreen();
		Object::draw_Pianoroll();
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