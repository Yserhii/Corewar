
#include "op.h"
#include "asm.h"

void	ft_fork(t_token *tmp_token, t_asm *head, int nb)
{
	int		n;
	t_token	*op;

	n = 0;
	op = tmp_token;
	hex_con(nb, 1, head);
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation fork", tmp_token->next->name);
	hex_con(n, 2, head);
}
