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
	t_kar	*tmp;
	int		i;
	int16_t	dir;

	i = -1;
	tmp = vm->kar;
	if (!(new = (t_kar *)ft_memalloc(sizeof(t_kar))))
		vm_exit(9);
	while (++i < REG_NUMBER)
		new->reg[i] = kar->reg[i];
	new->carry = kar->carry;
	new->id = ++vm->num_kar;
	new->bot_id = kar->bot_id;
	new->live = kar->live;
	dir = (int16_t)take_arg(vm, (kar->pos + 1), 2) % IDX_MOD;
	new->pos = (kar->pos + dir) % MEM_SIZE;
	new->next = vm->kar;
	vm->kar->back = new;
	vm->kar = new;
	op_recognize(vm, new);
	if (new->cicles_to_wait > 0)
		new->cicles_to_wait--;
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | fork %d (%d)\n", kar->id, dir, kar->pos + dir);
	print_adv(vm, kar->pos, kar->pos = (kar->pos + g_op[kar->op_id].dir_size + 1) % MEM_SIZE);
}
