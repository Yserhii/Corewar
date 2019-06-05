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
# define IND				2
# define REG				1

typedef struct		s_bot
{
	int				id;
	uint32_t		size;
	uint8_t			name[PROG_NAME_LENGTH];
	uint8_t			comment[COMMENT_LENGTH];
	uint8_t			*code;
	uint8_t			*all_info;
}					t_bot;

typedef struct		s_kar
{
	int				zjmp;

	int				id;
	int				carry;
	uint32_t		pos;
	uint32_t		op_id;
	uint32_t		bot_id;
	uint32_t		live;
	uint32_t		cicles_to_wait;
	uint32_t		reg[REG_NUMBER];
	struct s_kar	*next;
	struct s_kar	*back;
}					t_kar;



typedef struct		s_vm
{
	// flags
	int				nbr_cycles;
	int				v_fl;
	int				ncurs;

	//fd
	int				fd[5];

	//map
	uint8_t			map[MEM_SIZE];

	int				last_say_live;
	int				cycles_from_start;
	int				cycles_to_die;
	int				num_of_life;
	int				number_of_checks;

	//bots
	int				num_bot;
	t_bot			**bot;
	t_kar			*kar;

	//output
}					t_vm;


// for oper
typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		num_arg;
	uint8_t		is_args_types;
	uint8_t		args_types[3];
	uint8_t		dir_size;
	int			wait;
}				t_op;

void				read_valid_av(int ac,char **av, t_vm *vm);
void				fun_for_help(void);
void				read_valid_bot(t_vm *vm);
void				initialization_map(t_vm *vm);

void				battle(t_vm *vm);
void				killing_check(t_vm *vm);

//for operations
int					take_arg(t_vm *vm, int pos, int size_arg);
int					step_for_not_valid(uint8_t *arg, t_kar *kar, int num_arg);
void				give_reg_to_map(t_vm *vm, int pos, int size_arg, uint32_t src);
void				check_argv_for_op(uint8_t *arg, t_vm *vm, t_kar *kar);
void				op_recognize(t_vm *vm, t_kar *kar);



void				vm_live(t_vm *vm, t_kar *kar);
void				vm_ld(t_vm *vm, t_kar *kar);
void				vm_st(t_vm *vm, t_kar *kar);
void				vm_add(t_vm *vm, t_kar *kar);
void				vm_sub(t_vm *vm, t_kar *kar);
void				vm_and(t_vm *vm, t_kar *kar);
void				vm_or(t_vm *vm, t_kar *kar);
void				vm_xor(t_vm *vm, t_kar *kar);
void				vm_zjmp(t_vm *vm, t_kar *kar);
void				vm_ldi(t_vm *vm, t_kar *kar);
void				vm_sti(t_vm *vm, t_kar *kar);
void				vm_fork(t_vm *vm, t_kar *kar);
void				vm_lld(t_vm *vm, t_kar *kar);
void				vm_lldi(t_vm *vm, t_kar *kar);
void				vm_lfork(t_vm *vm, t_kar *kar);
void				vm_aff(t_vm *vm, t_kar *kar);

// OUTPUT

void				show_winner(t_vm *vm);
void				print_map(t_vm *vm);
void				print_adv(t_vm *vm, int start, int end);

static void			(*g_opers[17])() = {0, &vm_live, &vm_ld, &vm_st,
	&vm_add, &vm_sub, &vm_and, &vm_or, &vm_xor, &vm_zjmp, &vm_ldi, &vm_sti,
	&vm_fork, &vm_lld, &vm_lldi, &vm_lfork, &vm_aff};

static t_op g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR | 0 | 0},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "ld",
		.code = 0x02,
		.num_arg = 2,
		.is_args_types = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.wait = 5
	},
	{
		.name = "st",
		.code = 0x03,
		.num_arg = 2,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.dir_size = 4,
		.wait = 5
	},
	{
		.name = "add",
		.code = 0x04,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "sub",
		.code = 0x05,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "and",
		.code = 0x06,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "or",
		.code = 0x07,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "xor",
		.code = 0x08,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 20
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.wait = 25
	},
	{
		.name = "sti",
		.code = 0x0B,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.dir_size = 2,
		.wait = 25
	},
	{
		.name = "fork",
		.code = 0x0C,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 800
	},
	{
		.name = "lld",
		.code = 0x0D,
		.num_arg = 2,
		.is_args_types = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.wait = 50
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 1000
	},
	{
		.name = "aff",
		.code = 0x10,
		.num_arg = 1,
		.is_args_types = 1,
		.args_types = {T_REG, 0, 0},
		.dir_size = 4,
		.wait = 2
	}
};
#endif
