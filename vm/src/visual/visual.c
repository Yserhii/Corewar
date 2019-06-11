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

// void	check_kar()

void	print_map_vis(t_vm *vm, WINDOW *win)
{
	uint32_t	i;
	t_kar		*kar;

	i = 0;
	while (i < MEM_SIZE)
	{
		// if (vm->inf_vis[i] > 0)
			// wattron(win, COLOR_PAIR(vm->inf_vis[i]));
		kar = vm->kar;
		while (kar)
			if (kar->pos == i)
				break ;
			else
				kar = kar->next;
		if (kar && kar->pos == i)
			wattron(win, COLOR_PAIR(kar->bot_id + 4));
		else if (vm->inf_vis[i] > 0)
			wattron(win, COLOR_PAIR(vm->inf_vis[i]));
		wprintw(win, "%02x", vm->map[i]);
		if (kar && kar->pos == i)
			wattroff(win, COLOR_PAIR(kar->bot_id + 4));
		if (vm->inf_vis[i] > 0)
			wattroff(win, COLOR_PAIR(vm->inf_vis[i]));
		if ((i + 1) % 64 != 0)
			wprintw(win, " ");
		i++;
	}
}

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
	while (vm->bot[i] && i < 4)
	{
		wattron(win, COLOR_PAIR(i + 1));
		if (vm->bot[i])
		{
			mvwprintw(win, 14 + row, 5, "Player - %d : %s", row + 1, vm->bot[i]->name);
			row++;
		}
		wattroff(win, COLOR_PAIR(i + 1));
		i++;
	}
}

void		set_colors()
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_BLUE);
	init_pair(7, COLOR_WHITE, COLOR_GREEN);
	init_pair(8, COLOR_WHITE, COLOR_YELLOW);
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
	noecho();
	refresh();
	wrefresh(map);
	wrefresh(menu);
	halfdelay(1);
	getch();
}
