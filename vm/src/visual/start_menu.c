/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:15:12 by omaltsev          #+#    #+#             */
/*   Updated: 2019/06/12 13:15:15 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "visual.h"

void		set_colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(8, COLOR_WHITE, COLOR_GREEN);
}

void		init_visual(t_vm *vm)
{
	vm->vis = (t_vis *)ft_memalloc(sizeof(t_vis));
	initscr();
	curs_set(0);
	vm->vis->map = newwin(64, 191, 5, 1);
	vm->vis->menu = newwin(64, 50, 5, 193);
	set_colors();
}

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
		if (key == 65 || key == 66)
			position = (key == 65 ? 0 : 1);
		else if (key == 10 && position == 1)
			break ;
		else if (key == 10 && position == 0)
			return (0);
	}
	return (1);
}

int			start_menu(void)
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
	res = menu(win, x, y);
	endwin();
	return (res);
}
