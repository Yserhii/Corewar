/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:54:21 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:54:22 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_fork(t_vm *vm, t_kar *kar)
{
	t_kar	*new;
	int		i;
	int		start;

	i = -1;
	start = kar->pos;
	if (!(new = (t_kar *)ft_memalloc(sizeof(t_kar))))
		exit(ft_printf("{red}Malloc error{eoc}\n"));
	vm->num_kar++;
	while (++i < REG_NUMBER)
		new->reg[i] = kar->reg[i];
	new->carry = kar->carry;
	new->id = vm->num_kar;
	new->bot_id = kar->bot_id;
	new->live = kar->live;
	new->pos = (take_arg(vm, (kar->pos + 1), 2) % IDX_MOD) % MEM_SIZE;
	new->next = vm->kar;
	new->next->back = new;
	vm->kar = new;
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | fork %d (%d)\n", kar->id, vm->map[(start + 2) % MEM_SIZE], vm->map[(start + 2) % MEM_SIZE]);
	print_adv(vm, start, kar->pos);
}
