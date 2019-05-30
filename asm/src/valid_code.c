/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:50:49 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/30 11:50:51 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	valid_operation2(t_token *token)
{
	if (ft_strequ(token->name, "zjmp"))
		valid_zjmp(token);
	else if (ft_strequ(token->name, "ldi"))
		valid_ldi(token, 10);
	else if (ft_strequ(token->name, "sti"))
		valid_sti(token);
	else if (ft_strequ(token->name, "fork"))
		valid_fork(token, 12);
	else if (ft_strequ(token->name, "lld"))
		valid_ld(token, 13);
	else if (ft_strequ(token->name, "lldi"))
		valid_ldi(token, 14);
	else if (ft_strequ(token->name, "lfork"))
		valid_fork(token, 15);
	else if (ft_strequ(token->name, "aff"))
		valid_aff(token);
	else
		error("Invalid instruction", token->name);
}

void	valid_operation(t_token *token)
{
	if (ft_strequ(token->name, "live"))
		valid_live(token);
	else if (ft_strequ(token->name, "ld"))
		valid_ld(token, 2);
	else if (ft_strequ(token->name, "st"))
		valid_st(token);
	else if (ft_strequ(token->name, "add"))
		valid_add(token);
	else if (ft_strequ(token->name, "sub"))
		valid_sub(token);
	else if (ft_strequ(token->name, "and"))
		valid_and_or(token, 6);
	else if (ft_strequ(token->name, "or"))
		valid_and_or(token, 7);
	else if (ft_strequ(token->name, "xor"))
		valid_and_or(token, 8);
	else
		valid_operation2(token);
}

void	valid_code(t_asm *head)
{
	t_token	*token;

	token = head->token;
	while (token)
	{
		if (token->type == OP)
			valid_operation(token);
		token = token->next;
	}
}
