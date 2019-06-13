/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:15:00 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:15:02 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	valid_st(t_token *token)
{
	token = token->next;
	if (token->type != REG)
		error("Bad argument for operation st", token->name);
	token = token->next;
	if (!token || token->type == OP || token->type == LABEL)
		error("Too few arguments for st\n", NULL);
	if (token->type != REG && token->type != IND && token->type != IND_L)
		error("Bad argument for operation st", token->name);
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		error("Too many arguments for st\n", NULL);
}

void	st(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	op = tmp_token;
	hex_con(3, 1, head);
	if (tmp_token->next->next->type == REG)
		n = 80;
	else
		n = 112;
	hex_con(n, 1, head);
	n = ft_atoi(tmp_token->next->name + 1);
	hex_con(n, 1, head);
	tmp_token = tmp_token->next->next;
	if (tmp_token->type == REG)
	{
		n = ft_atoi(tmp_token->name + 1);
		hex_con(n, 1, head);
		return ;
	}
	if (tmp_token->type == IND_L)
		n = label_pos(head, tmp_token->name) - op->pos;
	else
		n = ft_atoi(tmp_token->name);
	hex_con(n, 2, head);
}
