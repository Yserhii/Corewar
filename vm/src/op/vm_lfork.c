/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:54:58 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:55:00 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_lfork(t_vm *vm, t_kar *kar)
{
	t_kar	*new;
	int		i;
	int16_t dir;

	i = -1;
	if (!(new = (t_kar *)ft_memalloc(sizeof(t_kar))))
		vm_exit(9);
	while (++i < REG_NUMBER)
		new->reg[i] = kar->reg[i];
	new->carry = kar->carry;
	new->id = ++vm->num_kar;
	new->bot_id = kar->bot_id;
	new->live = kar->live;
	dir = (int16_t)take_arg(vm, (kar->pos + 1), 2);
	new->pos = (kar->pos + dir) % MEM_SIZE;
	new->next = vm->kar;
	vm->kar->back = new;
	vm->kar = new;
	op_recognize(vm, new);
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | lfork %d (%d)\n", kar->id, dir, kar->pos + dir);
	print_adv(vm, kar->pos, kar->pos += (g_op[kar->op_id].dir_size + 1));
	kar->pos = kar->pos % MEM_SIZE;
}

///////////////////////////////////////////////////////////////////////////////////////
// void	vm_lfork(t_vm *vm, t_kar *kar)
// {
// 	t_kar	*new;
// 	int		i;
// 	int16_t dir;

// 	i = -1;
// 	if (!(new = (t_kar *)ft_memalloc(sizeof(t_kar))))
// 		vm_exit(9);
// 	while (++i < REG_NUMBER)
// 		new->reg[i] = kar->reg[i];
// 	new->carry = kar->carry;
// 	new->id = ++vm->num_kar;
// 	new->bot_id = kar->bot_id;
// 	new->live = kar->live;
// 	dir = (int16_t)take_arg(vm, (kar->pos + 1), 2);
// 	new->pos = (kar->pos + dir) % MEM_SIZE;
// 	new->next = vm->kar;
// 	vm->kar->back = new;
// 	vm->kar = new;
// 	op_recognize(vm, new);
// 	if (new->cicles_to_wait > 0)
// 		new->cicles_to_wait--;
// 	if (vm->v_fl == 4 || vm->v_fl == 30)
// 		ft_printf("P% 5d | lfork %d (%d)\n", kar->id, dir, kar->pos + dir);
// 	print_adv(vm, kar->pos, kar->pos = (kar->pos + g_op[kar->op_id].dir_size + 1) % MEM_SIZE);;

// }

