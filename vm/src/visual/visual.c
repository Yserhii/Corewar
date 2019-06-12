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

void	show_winner_vis(t_vm *vm)
{
	int		winner;

	winner = vm->last_say_live - 1;
	nodelay(stdscr, FALSE);
	wattron(vm->vis->menu, A_BOLD);
	wattron(vm->vis->menu, COLOR_PAIR(winner + 4));
	mvwprintw(vm->vis->menu, 25, 5, "Winner: %s", vm->bot[winner]->name);
	wattroff(vm->vis->menu, COLOR_PAIR(winner + 4));
	wattroff(vm->vis->menu, A_BOLD);
	refresh();
	wrefresh(vm->vis->menu);
}

void	print_map_vis(t_vm *vm, WINDOW *win)
{
	int		bot;
	int		i;

	bot = -1;
	while (++bot < vm->num_bot)
	{
		i = -1;
		wattron(win, COLOR_PAIR(bot + 1));
		while (++i < MEM_SIZE)
		{
			if (vm->inf_vis[i] == bot + 1)
			{
				mvwprintw(win, i / 64, (i % 64) * 3, "%02x", vm->map[i]);
			}
		}
		wattroff(win, COLOR_PAIR(bot + 1));
	}
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (vm->inf_vis[i] == 0)
			mvwprintw(win, i / 64, (i % 64) * 3, "%02x", vm->map[i]);
	}
}

void	print_kar(t_vm *vm, WINDOW *win)
{
	t_kar		*kar;

	kar = vm->kar;
	while (kar)
	{
		wattron(win, COLOR_PAIR(kar->bot_id + 4));
		mvwprintw(win, kar->pos / 64, (kar->pos % 64) * 3,
				"%02x", vm->map[kar->pos]);
		wattroff(win, COLOR_PAIR(kar->bot_id + 4));
		kar = kar->next;
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
			mvwprintw(win, 14 + row, 5, "Player %d : %s", row + 1,
				vm->bot[i]->name);
			row++;
		}
		wattroff(win, COLOR_PAIR(i + 1));
		i++;
	}
}

void	visualisation(t_vm *vm)
{
	// WINDOW		*map;
	// WINDOW		*menu;

	// initscr();
	// curs_set(0);
	// map = newwin(64, 191, 5, 1);
	// menu = newwin(64, 50, 5, 193);
	// set_colors();
	box(vm->vis->menu, 0, 0);
	print_map_vis(vm, vm->vis->map);
	print_kar(vm, vm->vis->map);
	print_menu(vm, vm->vis->menu);
	noecho();
	refresh();
	wrefresh(vm->vis->map);
	wrefresh(vm->vis->menu);
	nodelay(stdscr, TRUE);
	if (getch() == 10)
	{
		while (getch() != 10)
			;
	}
}
