#pragma once

namespace	Game
{
	//--- �萔�錾 ---
	enum mode {
		mode_title,
		mode_game,
		mode_over,
	};
	//--- �֐��錾 ---

	extern int roll_img;
}

extern	void	game_init(void);
extern	void	game_main(void);
extern	void	game_end(void);