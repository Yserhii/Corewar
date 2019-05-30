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

void	ld_error(char *name, int nb)
{
	if (name == NULL)
	{
		if (nb == 2)
			error("Too many arguments for ld\n", NULL);
		error("Too many arguments for lld\n", NULL);
	}
	else
	{
		if (nb == 2)
			error("Bad argument for ld", name);
		error("Bad argument for lld", name);
	}
}

void	valid_ld(t_token *token, int nb)
{
	token = token->next;
	if (token->type != DIR && token->type != DIR_L &&
		token->type != IND && token->type != IND_L)
		ld_error(token->name, nb);
	token = token->next;
	if (!token || token->type == OP || token->type == LABEL)
	{
		if (nb == 2)
			error("Too few arguments for ld\n", NULL);
		error("Too few arguments for lld\n", NULL);
	}
	if (token->type != REG)
		ld_error(token->name, nb);
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		ld_error(NULL, nb);
}

void	what_arg_ld(t_token *op, t_token *tmp_token, t_asm *head)
{
	int	n;

	n = 0;
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
	{
		if (tmp_token->type == DIR_L)
			n = label_pos(head, tmp_token->name + 1) - op->pos;
		else
			n = ft_atoi(tmp_token->name + 1);
		hex_con(n, 4, head);
	}
	else if (tmp_token->type == IND || tmp_token->type == IND_L)
	{
		if (tmp_token->type == IND_L)
			n = label_pos(head, tmp_token->name) - op->pos;
		else
			n = ft_atoi(tmp_token->name);
		hex_con(n, 2, head);
	}
}

void	ld(t_token *tmp_token, t_asm *head, int nb)
{
	t_token	*op;
	int		n;

	op = tmp_token;
	hex_con(nb, 1, head);
	if (tmp_token->next->type != DIR && tmp_token->next->type != DIR_L)
		hex_con(208, 1, head);
	else
		hex_con(144, 1, head);
	what_arg_ld(op, tmp_token->next, head);
	tmp_token = tmp_token->next->next;
	n = ft_atoi(tmp_token->name + 1);
	hex_con(n, 1, head);
}
