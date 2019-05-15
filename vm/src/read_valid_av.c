/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:16:09 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/15 15:16:11 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_valid_av(int ac,char **av, t_vm *vm)
{
	int		i;
	int		j;
	int		n;
	int		fd_tmp[3];

	i = 0;
	if (ac == 1 || ac > 15)
		exit(ft_printf("{red}So many av or not av{eoc}\n"));
	while (++i < ac)
	{
		if (ft_strcmp("-dump", av[i]))
		{
			if (ft_allnum(av[++i]))
				exit(ft_printf("{red}Not valid nuber cycles{eoc}\n"));
			vm->nbr_cycles = ft_atoi(av[i]);
			if (vm->nbr_cycles > CYCLE_TO_DIE)
				exit(ft_printf("{red}Number cycles more cycle to die{eoc}\n"));
		}
		else if (ft_strcmp("-n", av[i]))
		{
			if (!ft_allnum(av[++i]) && (n = ft_atoi(av[i])) && n > 0 && n < 5)
			{
				if (!ft_strcmp(ft_strrchr(av[++i], '.'), ".cor") && !vm->fd[n - 1])
					vm->fd[n - 1] = open(av[i], O_RDONLY);
				else
					exit(ft_printf("{red}Not valid file with bot (*.cor) or you use two identical id players{eoc}\n"));
			}
			else
				exit(ft_printf("{red}Id players must be int from 1 to 4{eoc}\n"));
		}
		else if (!ft_strcmp(ft_strrchr(av[i], '.'), ".cor"))
		{
			j = 0;
			while (fd_tmp[j])
				j++;
			if (j < 4)
				fd_tmp[j] = av[i];
			else
				exit(ft_printf("{red}You give so meny players{eoc}\n"));

		}

	}
}

