
#include "op.h"
#include "asm.h"

void	zjmp(t_token *tmp_token, t_asm *head)
{
	int	n;
	t_token	*op;

	n = 0;
	op = tmp_token;
	head->hex_code = ft_strjoin(head->hex_code, hex_con(9, 1));
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation zjmp", tmp_token->next->name);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 2));
}
