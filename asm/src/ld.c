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

void	second_arg_ld(t_token *tmp_token, int nb, t_asm *head)
{
	int	n;

	n = 0;
	tmp_token = tmp_token->next;
	if (!tmp_token || tmp_token->type == OP || tmp_token->type == LABEL)
	{
		if (nb == 2)
			error("Too few arguments for ld\n", NULL);
		error("Too few arguments for lld\n", NULL);
	}
	if (tmp_token->type != REG)
		ld_error(tmp_token->name, nb);
	n = ft_atoi(tmp_token->name + 1);
	hex_con(n, 1, head);
	tmp_token = tmp_token->next;
	if (tmp_token && tmp_token->type != OP && tmp_token->type != LABEL)
		ld_error(NULL, nb);
}

void	what_arg_ld(t_token *op, t_token *tmp_token, t_asm *head, int nb)
{
	int	n;

	n = 0;
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
		ld_error(tmp_token->next->name, nb);
	second_arg_ld(tmp_token->next, nb, head);
}

void	ld(t_token *tmp_token, t_asm *head, int nb)
{
	t_token	*op;

	op = tmp_token;
	hex_con(nb, 1, head);
	if (tmp_token->next->type != DIR && tmp_token->next->type != DIR_L)
		hex_con(208, 1, head);
	else
		hex_con(144, 1, head);
	what_arg_ld(op, tmp_token, head, nb);
}
