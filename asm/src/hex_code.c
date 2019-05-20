
#include "op.h"
#include "asm.h"

void	choose_operation(t_token *tmp_token, t_asm *head)
{
	if (ft_strequ(tmp_token->name, "live"))
	{
		printf("tuut 1\n");
		live(tmp_token, head);
	}
	if (ft_strequ(tmp_token->name, "ld"))
	{
		printf("tuut 2\n");
		ld(tmp_token, head, 2);
	}
	if (ft_strequ(tmp_token->name, "st"))
		st(tmp_token, head);
	if (ft_strequ(tmp_token->name, "add"))
		add(tmp_token, head);
	if (ft_strequ(tmp_token->name, "sub"))
		sub(tmp_token, head);
	if (ft_strequ(tmp_token->name, "and"))
		ft_and_or(tmp_token, head, 6);
	if (ft_strequ(tmp_token->name, "or"))
		ft_and_or(tmp_token, head, 7);
	if (ft_strequ(tmp_token->name, "xor"))
		ft_and_or(tmp_token, head, 8);
	if (ft_strequ(tmp_token->name, "zjmp"))
	{
		printf("tuut 3\n");
		zjmp(tmp_token, head);
	}
	if (ft_strequ(tmp_token->name, "ldi"))
		ldi(tmp_token, head, 10);
	if (ft_strequ(tmp_token->name, "sti"))
		sti(tmp_token, head);
	if (ft_strequ(tmp_token->name, "fork"))
		ft_fork(tmp_token, head, 12);
	if (ft_strequ(tmp_token->name, "lld"))
		ld(tmp_token, head, 13);
	if (ft_strequ(tmp_token->name, "lldi"))
		ldi(tmp_token, head, 14);
	if (ft_strequ(tmp_token->name, "lfork"))
		ft_fork(tmp_token, head, 15);
	if (ft_strequ(tmp_token->name, "aff"))
		aff(tmp_token, head);
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
