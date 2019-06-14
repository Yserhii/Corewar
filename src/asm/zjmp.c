/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:15:41 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:15:45 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	valid_zjmp(t_token *token, t_asm *head)
{
	token = token->next;
	if (token->type != DIR && token->type != DIR_L)
		error("Bad argument for operation zjmp", token->name);
	token->type == DIR_L ? label_pos(head, token->name + 1) : 0;
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		error("Too many arguments for zjmp\n", NULL);
}

void	zjmp(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	n = 0;
	op = tmp_token;
	hex_con(9, 1, head);
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	hex_con(n, 2, head);
}
