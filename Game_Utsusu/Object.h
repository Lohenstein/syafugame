#pragma once

namespace Object
{
	void	draw_Pianoroll(void);
	void	init_Pianoroll(void);
	void	place_Pianoroll(void);
	void	draw_Gamescreen(void);
	void	out_Songdata(void);
	extern int piano_roll[64][88];

	class gui {
	public:
		int stats;
		int x;
		int y;
		int h;
		int w;
		unsigned int normal_color;
		unsigned int over_color;

		bool draw_Button(int mx, int my, int mw, int mh, unsigned int normal, unsigned int over, const wchar_t *str);
	};
}
