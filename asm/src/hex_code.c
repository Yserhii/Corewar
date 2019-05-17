
#include "op.h"
#include "asm.h"

void	choose_operation(t_token *tmp_token, t_asm *head)
{
	if (ft_strequ(tmp_token->name, "live"))
		live(tmp_token, head);
}

void	code_to_hex(t_asm *head)
{
	t_token	*tmp_token;

	tmp_token = head->token;
	while (tmp_token)
	{
		if (tmp_token->type == OP)
			choose_operation(tmp_token, head);
		tmp_token = tmp_token->next;
	}
}
