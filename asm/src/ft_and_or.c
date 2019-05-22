
#include "op.h"
#include "asm.h"

int		arg_code_and_or(t_token *tmp_token)
{
	int	code;

	code = 0;
	if (tmp_token->type == REG)
		code += 64;
	else if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 128;
	else if (tmp_token->type == IND || tmp_token->type == IND_L)
		code += 128 + 64;
	else
		error("Bat argument for operation and", tmp_token->next->name);
	tmp_token = tmp_token->next;
	if (tmp_token->type == REG)
		code += 16;
	else if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 32;
	else if (tmp_token->type == IND || tmp_token->type == IND_L)
		code += 32 + 16;
	else
		error("Bat argument for operation and", tmp_token->next->name);
	if (tmp_token->next->type != REG)
		error("Bat argument for operation and", tmp_token->next->name);
	code += 4;
	return (code);
}

void	what_type(t_token *tmp_token, t_asm *head, t_token *op)
{
	int	n;

	n = 0;
	if (tmp_token->type == REG)
	{
		n = ft_atoi(tmp_token->name + 1);
		hex_con(n, 1, head);
	}
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
	{
		if (tmp_token->type == DIR)
			n = ft_atoi(tmp_token->name + 1);
		else
			n = label_pos(head, tmp_token->name + 1) - op->pos;
		hex_con(n, 4, head);
	}
	if (tmp_token->type == IND || tmp_token->type == IND_L)
	{
		if (tmp_token->type == IND)
			n = ft_atoi(tmp_token->name);
		else
			n = label_pos(head, tmp_token->name + 1) - op->pos;
		hex_con(n, 2, head);
	}
}

void	ft_and_or(t_token *tmp_token, t_asm *head, int nb)
{
	int	i;
	t_token *op;

	i = -1;
	op = tmp_token;
	hex_con(nb, 1, head);
	hex_con(arg_code_and_or(tmp_token->next), 1, head);
	while (++i < 2)
	{
		what_type(tmp_token->next, head, op);
		tmp_token = tmp_token->next;
	}
	what_type(tmp_token->next, head, op);
	//исправить еррор под разные операции!!!!!!!
}
