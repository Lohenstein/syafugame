#pragma once

namespace	Game
{
	extern int mode;
	//--- ’è”éŒ¾ ---
	extern enum mode {
		mode_title,
		mode_game,
		mode_over,
		mode_menu,
	};
	//--- ŠÖ”éŒ¾ ---
}

extern	void	game_init(void);
extern	void	game_main(void);
extern	void	game_end(void);