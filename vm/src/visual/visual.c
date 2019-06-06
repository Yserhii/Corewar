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

// void	check_kar(WINDOW *win, t_vm *vm, int i)
// {
// 	t_kar	*kar;
// 	t_kar	*start;

// 	start = NULL;
// 	while
// }

void	print_map_vis(t_vm *vm, WINDOW *win)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (vm->map[i] != 0x0)
			wattron(win, COLOR_PAIR(1));
		// check_kar(win, vm, i);
		wprintw(win, "%02x", vm->map[i]);
		if ((i + 1) % 64 != 0)
			wprintw(win, " ");
		wattroff(win, COLOR_PAIR(1));
		i++;
	}
}

// void	print_kar(t_vm *vm, WINDOW *win)
// {
// 	t_kar		*start;
// 	t_kar		*kar;

// 	start = NULL;
// 	kar = vm->kar;
// 	wattron(win, COLOR_PAIR(2));
// 	while (kar != start)
// 	{

// 	}
// 	wattroff(win, COLOR_PAIR(2));
// }

void	print_menu(t_vm *vm, WINDOW *win)
{
	int		i;
	int		row;

	i = 0;
	row = 0;
	mvwprintw(win, 5, 5, "Cycles: %d", vm->cycles_from_start);
	mvwprintw(win, 7, 5, "Cycles to die: %d", vm->cycles_to_die);
	mvwprintw(win, 9, 5, "Lives: %d", vm->num_of_life);
	mvwprintw(win, 11, 5, "Checks: %d", vm->number_of_checks);
	wattron(win, COLOR_PAIR(1));
	while (vm->bot[i] && i < 4)
	{
		if (vm->bot[i])
		{
			mvwprintw(win, 14 + row, 5, "Player - %d : %s", row + 1, vm->bot[i]->name);
			row++;
		}
		i++;
	}
	wattroff(win, COLOR_PAIR(1));
}

void		set_colors()
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
}

void	visualisation(t_vm *vm)
{
	WINDOW		*map;
	WINDOW		*menu;

	initscr();
	curs_set(0);
	map = newwin(64, 191, 5, 1);
	menu = newwin(64, 50, 5, 193);
	set_colors();
	box(menu, 0, 0);
	print_map_vis(vm, map);
	print_menu(vm, menu);
	refresh();
	wrefresh(map);
	wrefresh(menu);
	halfdelay(10);
	getch();
}
