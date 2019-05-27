/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:12:36 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:40 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	ft_fork(t_token *tmp_token, t_asm *head, int nb)
{
	int		n;
	t_token	*op;

	n = 0;
	op = tmp_token;
	hex_con(nb, 1, head);
	tmp_token = tmp_token->next;
	if (!tmp_token || tmp_token->type == OP || tmp_token->type == LABEL)
	{
		if (nb == 12)
			error("Too few argumentd for fork", NULL);
		error("Too few argumentd for lfork", NULL);
	}
	if (tmp_token->type == DIR)
		n = ft_atoi(tmp_token->name + 1);
	else if (tmp_token->type == DIR_L)
		n = label_pos(head, tmp_token->name + 1) - op->pos;
	else
	{
		if (nb == 12)
			error("Bad argument for operation fork", tmp_token->name);
		error("Bad argument for operation lfork", tmp_token->name);
	}
	tmp_token = tmp_token->next;
	if (tmp_token->type != OP && tmp_token->type != LABEL)
	{
		if (nb == 12)
			error("Too many arguments for fork\n", NULL);
		error("Too many arguments for lfork\n", NULL);
	}
	hex_con(n, 2, head);
}
