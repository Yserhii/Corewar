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

static int		valid_dump(char **av, t_vm *vm, int i, int ac)
{
	if (++i >= ac || !ft_allnum(av[i]))
		exit(ft_printf("{red}Not valid nuber cycles{eoc}\n"));
	vm->nbr_cycles = ft_atoi(av[i]);
	if (vm->nbr_cycles > CYCLE_TO_DIE || vm->nbr_cycles < 1)
		exit(ft_printf("{red}Number cycles more than cycle to die or < 1{eoc}\n"));
	return (i);
}

static int		valid_n_id(int ac, char **av, t_vm *vm, int i)
{
	int		n;

	if (++i < ac && ft_allnum(av[i]) && (n = ft_atoi(av[i])) && n > 0 && n < 5)
		if (++i < ac && !ft_strcmp(ft_strrchr(av[i], '.'), ".cor") && !vm->fd[n - 1])
			if ((vm->fd[n - 1] = open(av[i], O_RDONLY)) < 1)
				exit(ft_printf("{red}Not valid file with bot (*.cor){eoc}\n"));
			else
				return (i);
		else
			exit(ft_printf("{red}Not valid file with bot (*.cor) or you use two identical id players{eoc}\n"));
	else
		exit(ft_printf("{red}Id players must be int from 1 to 4{eoc}\n"));
}

static int		valid_cor(char *av, int j, int *fd_tmp)
{
	if (j < 4)
		if ((fd_tmp[j] = open(av, O_RDONLY)) < 1)
			exit(ft_printf("{red}Not valid file with bot (*.cor){eoc}\n"));
		else
			return (j);
	else
		exit(ft_printf("{red}You give so many players{eoc}\n"));
}

static void		sort_fd_by_id(t_vm *vm, int *fd_tmp)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	j = -1;
	count = 0;
	while (++i < 5)
		if (!vm->fd[i])
			while (++j < 4)
			{
				if (!fd_tmp[j])
					continue ;
				if (i < 4)
					vm->fd[i] = fd_tmp[j];
				count++;
				break ;
			}
		else
			count++;
	if (count < 1 || count > 4)
		exit(ft_printf("{red}You give so many players{eoc}\n"));
	vm->num_bot = count;
}

void	read_valid_av(int ac,char **av, t_vm *vm)
{
	int		i;
	int		j;
	int		fd_tmp[5];

	i = 0;
	j = -1;
	if (ac == 1 || ac > 15)
		exit(ft_printf("{red}You give not valid arguments use [--help]{eoc}\n"));
	if (ac == 2 && !ft_strcmp("--help", av[1]))
		fun_for_help();
	ft_bzero(fd_tmp, sizeof(fd_tmp));
	while (++i < ac)
	{
		if (!ft_strcmp("-dump", av[i]))
			 i = valid_dump(av, vm, i, ac);
		else if (!ft_strcmp("-n", av[i]))
			i = valid_n_id(ac, av, vm, i);
		else if (!ft_strcmp(ft_strrchr(av[i], '.'), ".cor") && ++j <= 4)
			 j = valid_cor(av[i], j, fd_tmp);
		else
			exit(ft_printf("{red}You give not valid arguments use [--help]{eoc}\n"));
	}
	sort_fd_by_id(vm, fd_tmp);
}
