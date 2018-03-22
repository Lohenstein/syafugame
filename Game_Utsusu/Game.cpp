
#include "Main.h"

namespace Game
{
	int roll_img;
	int mode = mode_game;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< ÉQÅ[ÉÄèâä˙âª >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
	roll_img = LoadGraph(_T("data/img/piano.png"));
	//Object::Init();
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
		Input::mouse_Input();
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
		Object::draw_Gamescreen();
		Object::draw_Pianoroll();
		//Object::Draw();
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