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

void	karetka_init(t_vm *vm)
{
	int			i;
	int			dis_bet_bot;
	t_kar		*new;

	i = 0;
	dis_bet_bot = MEM_SIZE / vm->num_bot;
	while (++i <= vm->num_bot)
	{
		if (!(new = (t_kar*)ft_memalloc(sizeof(t_kar))))
			exit(ft_printf("{red}Malloc error{eoc}\n"));
		new->bot_id = i;
		new->id = i;
		new->reg[0] = -i;
		new->pos = dis_bet_bot * (i - 1);
		if (i > 1 && (vm->kar->back = new) && (new->next = vm->kar))
			vm->kar = new;
		else
			vm->kar = new;
	}
}

void	map_init(t_vm *vm)
{
	int		i;
	int		j;
	int		num_bot;
	int		dis_bet_bot;

	num_bot = -1;
	vm->cycles_to_die = CYCLE_TO_DIE;
	dis_bet_bot = MEM_SIZE / vm->num_bot;
	while (++num_bot < vm->num_bot)
	{
		j = -1;
		i = (dis_bet_bot * num_bot - 1);
		while ((dis_bet_bot * num_bot + (int)vm->bot[num_bot]->size) > ++i)
			vm->map[i] = vm->bot[num_bot]->code[++j];
	}
}

void	represen_players(t_vm *vm)
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

void	initialization_map(t_vm *vm)
{
	karetka_init(vm);
	map_init(vm);
	represen_players(vm);




// /////////////////////для печати//////////////

	// for(int i = 0, k = -1; i < 64; i++)
	// {
	// 	for(int l = 0; l < 64; l++)
	// 		ft_printf("%02x ", vm->map[++k]);
	// 	ft_printf("\n");
	// }
// 	//////////////////
}
