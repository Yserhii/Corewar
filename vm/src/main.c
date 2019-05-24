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

<<<<<<< HEAD
void	fun_for_help()
{
		exit(ft_printf("{yellow}NADA NAPISAT ZDES9 USEGE!!!!!!!!!{eoc}\n"));
=======
void	fun_for_help(void)
{
	exit(ft_printf("{yellow}NADA NAPISAT ZDES9 USEGE!!!!!!!!!{eoc}\n"));
>>>>>>> 869a7d72d6f7436b8aa9554e90ca698d869cb127
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
		exit(ft_printf("{red}Malloc error{eoc}\n"));
	read_valid_av(ac, av, vm);
	read_valid_bot(vm);

	return (0);
}
