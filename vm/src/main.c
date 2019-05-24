/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:52:25 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/15 13:52:27 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fun_for_help()
{
		exit(ft_printf("{yellow}NADA NAPISAT ZDES9 USEGE!!!!!!!!!{eoc}\n"));
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	vm = ft_memalloc(sizeof(t_vm));
	read_valid_av(ac, av, vm);
	read_valid_bot(vm);

	return (0);
}
