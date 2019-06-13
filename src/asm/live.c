/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:13:53 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:13:56 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	valid_live(t_token *token)
{
	token = token->next;
	if (token->type != DIR && token->type != DIR_L)
		error("Bad argument for operation live", token->name);
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		error("Too many arguments for live\n", NULL);
}

void	live(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	n = 0;
	op = tmp_token;
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	hex_con(1, 1, head);
	hex_con(n, 4, head);
}
