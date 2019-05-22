
#include "op.h"
#include "asm.h"

void	live(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	n = 5;
	op = tmp_token;
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation live", tmp_token->next->name);
	hex_con(1, 1, head);
	hex_con(n, 4, head);
}
