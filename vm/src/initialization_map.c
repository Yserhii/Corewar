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

void	initialization_map(t_vm *vm)
{
	int		i;
	int		num_bot;
	int		dis_bet_bot;

	i = 0;
	num_bot = 0;
	dis_bet_bot = MEM_SIZE / vm->num_bot;
	ft_memcpy(&vm->map[0], vm->bot[0]->code, vm->bot[0]->size);
	while(++num_bot < vm->num_bot)
		ft_memcpy(&vm->map[dis_bet_bot], vm->bot[num_bot]->code, sizeof(uint8_t));
	for(int n = 0, k; n <= 64; n++)
	{
		for(k = 0; k <= 64; k++)
			ft_printf("%x ", vm->map[k]);
	ft_printf("\n");
	}
}

