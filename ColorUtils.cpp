#include "AEntity.hpp"


// defined in ncurses
// COLOR_BLACK   0
// COLOR_RED     1
// COLOR_GREEN   2
// COLOR_YELLOW  3
// COLOR_BLUE    4
// COLOR_MAGENTA 5
// COLOR_CYAN    6
// COLOR_WHITE   7

//init_color
// enum
// {
// 	GREY = 10,
// 	BR_YELLOW,
// 	BR_GREEN,
// 	L_PINK,
// 	SKY_BLUE,
// 	BR_PINK,
// 	ORANGE
// };

// //init_pair
// enum
// {
// 	PAIR_GREY = 10,
// 	PAIR_BR_YELLOW,
// 	PAIR_BR_GREEN,
// 	PAIR_L_PINK,
// 	PAIR_ORANGE,
// 	PAIR_BR_PINK,
// 	PAIR_SKY_BLUE,
// 	PAIR_DEF
// };





void	init_colors(void)
{
	if (has_colors() != FALSE)
	{
		start_color();
        use_default_colors();
		init_color(GREY, 600, 800, 1000);
		init_color(BR_GREEN, 400, 1000, 400);
		init_color(BR_PINK, 1000, 0, 1000);
		init_color(L_PINK, 1000, 600, 600);
		init_color(ORANGE, 1000, 600, 200);
		init_color(SKY_BLUE, 0, 1000, 1000);

		init_pair(PAIR_BR_GREEN, BR_GREEN, -1);
		init_pair(PAIR_BR_PINK, BR_PINK, -1);
		init_pair(PAIR_L_PINK, L_PINK, -1);
		init_pair(PAIR_ORANGE, ORANGE, -1);
		init_pair(PAIR_SKY_BLUE, SKY_BLUE, -1);
		init_pair(PAIR_GREY, GREY, -1);
		init_pair(PAIR_RED, COLOR_RED, -1);
		init_pair(PAIR_GREEN, COLOR_GREEN, -1);
		init_pair(PAIR_YELLOW, COLOR_YELLOW, -1);
		init_pair(PAIR_BLUE, COLOR_BLUE, -1);
		init_pair(PAIR_MAGENTA, COLOR_MAGENTA, -1);
		init_pair(PAIR_CYAN, COLOR_CYAN, -1);
		init_pair(PAIR_DEF, COLOR_WHITE, -1);
	}
}


