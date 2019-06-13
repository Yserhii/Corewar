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

static void	sort_fd_by_id(t_vm *vm, int *fd_tmp)
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
		vm_exit(7);
	vm->num_bot = count;
}

void		read_valid_av(int ac, char **av, t_vm *vm)
{
	int		fd_tmp[5];

	if (ac == 1 || ac > 15)
		vm_exit(8);
	if (ac == 2 && !ft_strcmp("--help", av[1]))
		fun_for_help();
	ft_bzero(fd_tmp, sizeof(fd_tmp));
	vm->nbr_cycles = -1;
	while_for_read_valid_av(ac, av, vm, fd_tmp);
	if (vm->ncurs)
	{
		vm->nbr_cycles = -1;
		vm->v_fl = 0;
		vm->a_fl = 0;
	}
	sort_fd_by_id(vm, fd_tmp);
}
