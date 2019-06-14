/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:06:23 by yserhii           #+#    #+#             */
/*   Updated: 2019/06/09 13:06:29 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	show_winner(t_vm *vm)
{
	if (vm->last_say_live)
		ft_printf("Contestant %d, \"%s\", has won !\n",
					vm->last_say_live, vm->bot[vm->last_say_live - 1]->name);
}

void	print_map(t_vm *vm)
{
	int	i;
	int	oct;

	if (vm->oct64_fl)
		oct = 64;
	else
		oct = 32;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (!(i % oct))
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", vm->map[i]);
		if (!((i + 1) % oct) && i != 0)
			ft_printf("\n");
	}
}

void	print_adv(t_vm *vm, int start, int end)
{
	int		delta;
	int		i;

	if (vm->v_fl == 16 || vm->v_fl == 30)
	{
		delta = (end - start < 0) ? MEM_SIZE - start + end : end - start;
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", delta, start, end);
		i = -1;
		while (++i < delta)
			ft_printf("%02x ", vm->map[(start + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}

void	ft_show_alive_kars_tmp(t_vm *vm)
{
	t_kar	*kar;

	kar = vm->kar;
	ft_printf("\tALIVE KARS: ");
	while (kar)
	{
		ft_printf("#%d - %d[%02x] ", kar->id, kar->pos, vm->map[kar->pos]);
		if (!kar->next)
			break ;
		kar = kar->next;
	}
	ft_printf("ALIVE KARS backwards: ");
	while (kar)
	{
		ft_printf("[%d] ", kar->id);
		kar = kar->back;
	}
	ft_printf("\n");
}
