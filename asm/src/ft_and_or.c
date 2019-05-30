/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:12:52 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:54 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	and_or_error(char *name, int nb, int fl)
{
	if (name == NULL && fl == 0)
	{
		if (nb == 6)
			error("Too many arguments for and\n", NULL);
		if (nb == 7)
			error("Too many arguments for or\n", NULL);
		error("Too many arguments for xor\n", NULL);
	}
	else if (name == NULL && fl == 1)
	{
		if (nb == 6)
			error("Too few arguments for and\n", NULL);
		if (nb == 7)
			error("Too few arguments for or\n", NULL);
		error("Too few arguments for xor\n", NULL);
	}
	else
	{
		if (nb == 6)
			error("Bad argument for and", name);
		if (nb == 7)
			error("Bad argument for or", name);
		error("Bad argument for xor", name);
	}
}

void	valid_and_or(t_token *token, int nb)
{
	token = token->next->next;
	if (!token || token->type == OP || token->type == LABEL)
		and_or_error(NULL, nb, 1);
	token = token->next;
	if (!token || token->type == OP
	|| token->type == LABEL)
		and_or_error(NULL, nb, 1);
	if (token->type != REG)
		and_or_error(token->next->name, nb, 0);
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		and_or_error(NULL, nb, 0);
}

int		arg_code_and_or(t_token *tmp_token)
{
	int	code;

	code = 0;
	if (tmp_token->type == REG)
		code += 64;
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 128;
	if (tmp_token->type == IND || tmp_token->type == IND_L)
		code += 128 + 64;
	tmp_token = tmp_token->next;
	if (tmp_token->type == REG)
		code += 16;
	else if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 32;
	else if (tmp_token->type == IND || tmp_token->type == IND_L)
		code += 32 + 16;
	code += 4;
	return (code);
}

void	what_type(t_token *tmp_token, t_asm *head, t_token *op)
{
	int	n;

	n = 0;
	if (tmp_token->type == REG)
	{
		n = ft_atoi(tmp_token->name + 1);
		hex_con(n, 1, head);
	}
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
	{
		if (tmp_token->type == DIR)
			n = ft_atoi(tmp_token->name + 1);
		else
			n = label_pos(head, tmp_token->name + 1) - op->pos;
		hex_con(n, 4, head);
	}
	if (tmp_token->type == IND || tmp_token->type == IND_L)
	{
		if (tmp_token->type == IND)
			n = ft_atoi(tmp_token->name);
		else
			n = label_pos(head, tmp_token->name) - op->pos;
		hex_con(n, 2, head);
	}
}

void	ft_and_or(t_token *tmp_token, t_asm *head, int nb)
{
	int		i;
	t_token *op;

	i = -1;
	op = tmp_token;
	hex_con(nb, 1, head);
	hex_con(arg_code_and_or(tmp_token->next), 1, head);
	tmp_token = tmp_token->next;
	while (++i < 2)
	{
		what_type(tmp_token, head, op);
		tmp_token = tmp_token->next;
	}
	what_type(tmp_token, head, op);
}
