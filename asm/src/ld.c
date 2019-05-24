/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:13:37 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:13:39 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	what_arg_ld(t_token *op, t_token *tmp_token, t_asm *head, int n)
{
	if (tmp_token->next->type == DIR || tmp_token->next->type == DIR_L)
	{
		if (tmp_token->next->type == DIR_L)
			n = label_pos(head, tmp_token->next->name + 1) - op->pos;
		else
			n = ft_atoi(tmp_token->next->name + 1);
		hex_con(n, 4, head);
	}
	else if (tmp_token->next->type == IND || tmp_token->next->type == IND_L)
	{
		if (tmp_token->next->type == IND_L)
			n = label_pos(head, tmp_token->next->name) - op->pos;
		else
			n = ft_atoi(tmp_token->next->name);
		hex_con(n, 2, head);
	}
	else
		error("Bat argument for operation ld", tmp_token->next->name);
	tmp_token = tmp_token->next;
	if (tmp_token->next->type != REG)
		error("Bat argument for operation ld", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	hex_con(n, 1, head);
}

void	ld(t_token *tmp_token, t_asm *head, int nb)
{
	int		n;
	t_token	*op;

	op = tmp_token;
	hex_con(nb, 1, head);
	n = 0;
	if (tmp_token->next->type != DIR && tmp_token->next->type != DIR_L)
		hex_con(208, 1, head);
	else
		hex_con(144, 1, head);
	what_arg_ld(op, tmp_token, head, n);
}
