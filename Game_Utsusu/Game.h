#pragma once

namespace	Game
{
	extern int mode;
	//--- �萔�錾 ---
	extern enum mode {
		mode_title,
		mode_game,
		mode_over,
		mode_menu,
	};
	//--- �֐��錾 ---
}

extern	void	game_init(void);
extern	void	game_main(void);
extern	void	game_end(void);