#include "vm.h"
#include "visual.h"

int			menu(WINDOW *win, int x, int y)
{
	int		key;
	int		position;

	key = 0;
	position = 0;
	while (1)
	{
		if (position == 0)
			wattron(win, COLOR_PAIR(1));
		mvwprintw(win, y / 2, x / 2, "start game");
		wattroff(win, COLOR_PAIR(1));
		if (position == 1)
			wattron(win, COLOR_PAIR(1));
		mvwprintw(win, y / 2 + 1, x / 2, "close");
		wattroff(win, COLOR_PAIR(1));
		refresh();
		wrefresh(win);
		key = getch();
		printf("%d", key);
		if (key == 65 || key == 66)
			position = key == 65 ? 0 : 1;
		if (key == 10 && position == 1)
			break ;
		if (key == 27 || (key == 10 && position == 0))
			return (1);
	}
	return (0);
}

int			start_menu()
{
	int		x;
	int		y;
	int		res;
	WINDOW	*win;

	x = 300;
	y = 50;
	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	win = newwin(y, x, 0, 0);
	box(win, 0, 0);
	res = menu(win, x, y);
	getch();
	endwin();
	return (res);
}
