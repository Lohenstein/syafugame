#pragma once

namespace	Game
{
	//--- 定数宣言 ---
	enum mode {
		mode_title,
		mode_game,
		mode_over,
	};
	//--- 関数宣言 ---

	extern int roll_img;
}

extern	void	game_init(void);
extern	void	game_main(void);
extern	void	game_end(void);