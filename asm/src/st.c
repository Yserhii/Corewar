
#include "op.h"
#include "asm.h"

void	st(t_token *tmp_token, t_asm *head)
{
	int	n;
	t_token	*op;

	op = tmp_token;
	head->hex_code = ft_strjoin(head->hex_code, hex_con(3, 1));
	if (tmp_token->next->next->type == REG)
		head->hex_code = ft_strjoin(head->hex_code, hex_con(80, 1));
	else
		head->hex_code = ft_strjoin(head->hex_code, hex_con(122, 1));
	if (tmp_token->next->type != REG)
		error("Bat argument for operation st", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG)
	{
		n = ft_atoi(tmp_token->next->name + 1);
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
	}
	else if (tmp_token->next->type == IND || tmp_token->next->type == IND_L)
	{
		if (tmp_token->next->type == IND_L)
			n = label_pos(head, tmp_token->next->name + 1) - op->pos;
		else
			n = ft_atoi(tmp_token->next->name);
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
	}
}
