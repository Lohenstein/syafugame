
#include "Main.h"

namespace Game
{
	int mode = mode_game;
}

using	namespace Game;

/*------------------------------------------------------------------------------*
| <<< �Q�[�������� >>>
*------------------------------------------------------------------------------*/
void	game_init(void)
{
	Object::init_Pianoroll();
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
		break;
	case mode_game:
		Input::mouse_Input();
		break;
	case mode_over:
		break;
	}

	// �`��
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
| <<< �Q�[���I�� >>>
*------------------------------------------------------------------------------*/
void	game_end(void)
{
}