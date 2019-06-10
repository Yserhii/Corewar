/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:02:29 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/24 14:02:33 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	karetka_init(t_vm *vm)
{
	int			i;
	int			dis_bet_bot;
	t_kar		*new;

	i = 0;
	dis_bet_bot = MEM_SIZE / vm->num_bot;
	while (++i <= vm->num_bot)
	{
		if (!(new = (t_kar*)ft_memalloc(sizeof(t_kar))))
			vm_exit(9);
		new->bot_id = i;
		new->id = i;
		new->reg[1] = -i;
		new->pos = dis_bet_bot * (i - 1);
		if (i > 1)
		{
			vm->kar->back = new;
			new->next = vm->kar;
			vm->kar = new;
		}
		else
			vm->kar = new;
	}
	vm->num_kar = vm->num_bot;
}

static void	map_init(t_vm *vm)
{
	int		i;
	int		j;
	int		num_bot;
	int		dis_bet_bot;

	num_bot = -1;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_from_start = 1;
	dis_bet_bot = MEM_SIZE / vm->num_bot;
	while (++num_bot < vm->num_bot)
	{
		j = -1;
		i = (dis_bet_bot * num_bot - 1);
		while ((dis_bet_bot * num_bot + (int)vm->bot[num_bot]->size) > ++i)
			vm->map[i] = vm->bot[num_bot]->code[++j];
	}
	/* TEST POSTION OP - DELETE
	while ( ++i < MEM_SIZE)
		vm->map[i] = 0x01;*/
}

static void	represen_players(t_vm *vm)
{
	int		n;
	t_bot	**bot;

	n = -1;
	bot = vm->bot;
	ft_printf("Introducing contestants...\n");
	while (++n < vm->num_bot)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
					bot[n]->id, bot[n]->size, bot[n]->name, bot[n]->comment);
}

void		initialization_map(t_vm *vm)
{
	karetka_init(vm);
	map_init(vm);
	represen_players(vm);
}
