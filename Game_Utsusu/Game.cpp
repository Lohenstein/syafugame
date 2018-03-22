
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

	// �`��
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
| <<< �Q�[���I�� >>>
*------------------------------------------------------------------------------*/
void	game_end(void)
{
}