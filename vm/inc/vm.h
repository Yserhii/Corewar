/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:51:59 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/15 13:52:01 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>

typedef struct		s_bot
{
	int				size;
	char			*name;
}					t_bot;

typedef struct		s_vm
{
	int				nbr_cycles;
	int				num_bot;
	int				fd[3];
	unsigned char	*map;

	t_bot			**bot;
}					t_vm;

void	read_valid_av(int ac,char **av, t_vm *vm);

#endif
