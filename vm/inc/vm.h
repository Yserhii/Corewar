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

# define XXX ft_printf("================\n");

typedef struct		s_bot
{
	int				id;
	uint32_t		size;
	uint8_t			name[128];
	uint8_t			comment[2048];
	uint8_t			*code;
	uint8_t			*all_info;
}					t_bot;

typedef struct		s_vm
{
	// flags
	int				nbr_cycles;

	//fd
	int				fd[5];

	//map
	uint8_t			map[MEM_SIZE];

	//bots
	int				num_bot;
	t_bot			**bot;
}					t_vm;
//<<<<<<< HEAD
typedef struct	s_karetka
{
	unsigned int		pos;
	unsigned int		carry;
	unsigned int		bot_id;
	unsigned int		*reg;
	unsigned int		exec_op;
	unsigned int		live;
	unsigned int		cicles_to_wait;

	unsigned int		pc;

}					t_karetka;

void				read_valid_av(int ac,char **av, t_vm *vm);
void				fun_for_help(void);
void				read_valid_bot(t_vm *vm);
void				initialization_map(t_vm *vm);
#endif
