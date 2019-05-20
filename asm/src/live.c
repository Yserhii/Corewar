
#include "op.h"
#include "asm.h"

void	live(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	n = 0;
	op = tmp_token;
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation live", tmp_token->next->name);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(1, 1));
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 4));
}

void	ft_and_or(t_token *tmp_token, t_asm *head, int nb)
{
	int	n;
	int	i;
	t_token *op;

	i = -1;
	op = tmp_token;
	head->hex_code = ft_strjoin(head->hex_code, hex_con(nb, 1));
	// head->hex_code = ft_strjoin(head->hex_code, hex_code(arg_code() , 1))
	//del
	head->hex_code = ft_strjoin(head->hex_code, hex_con(0, 1));
	while (++i < 2)
	{
		if (tmp_token->next->type == REG)
		{
			n = ft_atoi(tmp_token->next->name + 1);
			head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
		}
		else if (tmp_token->next->type == DIR || tmp_token->next->type == DIR_L)
		{
			if (tmp_token->next->type == DIR)
				n = ft_atoi(tmp_token->next->name + 1);
			else
				n = label_pos(head, tmp_token->next->name + 1) - op->pos;
			head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 4));
		}
		else if (tmp_token->next->type == IND || tmp_token->next->type == IND_L)
		{
			if (tmp_token->next->type == IND)
				n = ft_atoi(tmp_token->next->name);
			else
				n = label_pos(head, tmp_token->next->name + 1) - op->pos;
			head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
		}
		else
			error("Bat argument for operation and", tmp_token->next->name);
		tmp_token = tmp_token->next;
	}
	//исправить еррор под разные операции!!!!!!!
}

void	ldi(t_token *tmp_token, t_asm *head, int nb)
{
	int	n;
	t_token	*op;

	op = tmp_token;
	head->hex_code = ft_strjoin(head->hex_code, hex_con(nb, 1));
	//head->hex_code = ft_strjoin(head->hex_code, hex_con(arg_cod, 1));
	//del
	head->hex_code = ft_strjoin(head->hex_code, hex_con(0, 1));
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == IND)
		n = ft_atoi(tmp_token->next->name);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else if (tmp_token->next->type == IND_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation ldi", tmp_token->next->name);
	if (tmp_token->next->type == REG)
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	else
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation ldi", tmp_token->next->name);
	if (tmp_token->next->type == REG)
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	else
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
	if (tmp_token->next->next->type != REG)
		error("Bat argument for operation ldi", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->next->name + 1);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
}

void	sti(t_token *tmp_token, t_asm *head)
{
	int	n;
	t_token	*op;

	op = tmp_token;
	head->hex_code = ft_strjoin(head->hex_code, hex_con(11, 1));
	//head->hex_code = ft_strjoin(head->hex_code, hex_con(arg_cod, 1));
	//del
	head->hex_code = ft_strjoin(head->hex_code, hex_con(0, 1));
	if (tmp_token->next->type != REG)
		error("Bat argument for operation sti", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == IND)
		n = ft_atoi(tmp_token->next->name);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else if (tmp_token->next->type == IND_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation sti", tmp_token->next->name);
	if (tmp_token->next->type == REG)
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	else
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
	printf("pip: %d\n", n);
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation sti", tmp_token->next->name);
	if (tmp_token->next->type == REG)
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	else
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
}
