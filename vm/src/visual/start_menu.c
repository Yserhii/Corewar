#include "vm.h"
#include "visual.h"

void		show_menu(WINDOW *win, int pos, int x, int y)
{
	int		i;
	int		elems;

	i = -1;
	elems = 2;
	while (++i < elems)
	{
		if (i == pos)
			wattron(win, COLOR_PAIR(1));
		if (i == 0)
			mvwprintw(win, y / 2, x / 2 - 2, "start game");
		else if (i == 1)
			mvwprintw(win, y / 2 + 1, x / 2, "close");
		wattroff(win, COLOR_PAIR(1));
	}
	noecho();
	refresh();
	wrefresh(win);
}

int			menu(WINDOW *win, int x, int y)
{
	int		key;
	int		position;

	key = 0;
	position = 0;
	while (1)
	{
		show_menu(win, position, x, y);
		key = getch();
		// printf("%d", key);
		if (key == 65 || key == 66)
			position = (key == 65 ? 0 : 1);
		else if (key == 10 && position == 1)
			break ;
		else if (key == 10 && position == 0)
			return (0);
	}
	return (1);
}

int			start_menu()
{
	int		x;
	int		y;
	int		res;
	WINDOW	*win;

	x = 200;
	y = 50;
	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	win = newwin(y, x, 0, 0);
	// box(win, 0, 0);
	res = menu(win, x, y);
	endwin();
	return (res);
}
