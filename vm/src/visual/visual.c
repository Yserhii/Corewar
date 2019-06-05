/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:03:40 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/29 16:03:41 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "visual.h"

void	print_map_vis(t_vm *vm, WINDOW *win)
{
	int		i;

	i = 0;
	wattron(win, COLOR_RED);
	while (i < MEM_SIZE)
	{
		wprintw(win, "%02x", vm->map[i]);
		if ((i + 1) % 64 != 0)
			wprintw(win, " ");
		i++;
	}
	wattroff(win, COLOR_RED);
}

void	print_menu(t_vm *vm, WINDOW *win)
{
	int		i;
    int		row;

	i = 0;
	row = 5;
	mvwprintw(win, row++, 5, "Cycles: ");
	while (vm->bot[i])
	{
		row++;
		mvwprintw(win, row + i, 5, "Bot %d - %s", i, vm->bot[i]->name);
		i++;
	}
}

void	set_pause()
{
	// while (1)
	// {
	// 	if (getch())
	// }
}

void	visualisation(t_vm *vm)
{
	WINDOW		*map;
	WINDOW		*menu;

	initscr();
	curs_set(0);
	map = newwin(64, 191, 5, 1);
	menu = newwin(64, 50, 5, 193);
	box(menu, 0, 0);
	print_map_vis(vm, map);
	print_menu(vm, menu);
	refresh();
	wrefresh(map);
	wrefresh(menu);
	halfdelay(50);
	if (getch() == 27)
		set_pause();
	endwin();
}
