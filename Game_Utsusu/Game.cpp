
#include "Main.h"

namespace Game
{
	int mode = mode_title;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< �Q�[�������� >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
	Object::Init();
	Menu::Init();
}
/*------------------------------------------------------------------------------*
| <<< �Q�[�����C�� >>>
*------------------------------------------------------------------------------*/
void	game_main(void)
{

	// ����
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

	// �`��
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
| <<< �Q�[���I�� >>>
*------------------------------------------------------------------------------*/
void	game_end(void)
{
}