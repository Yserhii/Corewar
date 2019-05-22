
#include "op.h"
#include "asm.h"

void	st(t_token *tmp_token, t_asm *head)
{
	int	n;
	t_token	*op;

	op = tmp_token;
	hex_con(3, 1, head);
	if (tmp_token->next->next->type == REG)
		hex_con(80, 1, head);
	else
		hex_con(122, 1, head);
	if (tmp_token->next->type != REG)
		error("Bat argument for operation st", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	hex_con(n, 1, head);
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG)
	{
		n = ft_atoi(tmp_token->next->name + 1);
		hex_con(n, 1, head);
	}
	else if (tmp_token->next->type == IND || tmp_token->next->type == IND_L)
	{
		if (tmp_token->next->type == IND_L)
			n = label_pos(head, tmp_token->next->name + 1) - op->pos;
		else
			n = ft_atoi(tmp_token->next->name);
		hex_con(n, 2, head);
	}
}
