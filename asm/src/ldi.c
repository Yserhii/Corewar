/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:13:44 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:13:48 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	ldi_error(char *name, int nb, int fl)
{
	if (name == NULL && fl == 0)
	{
		if (nb == 10)
			error("Too many arguments for ldi\n", NULL);
		error("Too many arguments for lldi\n", NULL);
	}
	else if (name == NULL && fl == 1)
	{
		if (nb == 10)
			error("Too few arguments for ldi\n", NULL);
		error("Too few arguments for lldi\n", NULL);
	}
	else
	{
		if (nb == 10)
			error("Bad argument for ldi", name);
		error("Bad argument for lldi", name);
	}
}

int		arg_cod_ldi(t_token *tmp_token, int nb)
{
	int	code;

	code = 0;
	if (!tmp_token || tmp_token->type == OP || tmp_token->type == LABEL)
		ldi_error(NULL, nb, 1);
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 128;
	else if (tmp_token->type == REG)
		code += 64;
	else if (tmp_token->type == IND || tmp_token->type == IND_L)
		code += 192;
	tmp_token = tmp_token->next;
	if (!tmp_token || tmp_token->type == OP || tmp_token->type == LABEL)
		ldi_error(NULL, nb, 1);
	if (tmp_token->type == REG)
		code += 16;
	else if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 32;
	else
		ldi_error(tmp_token->name, nb, 0);
	if (!tmp_token->next || tmp_token->next->type == OP || tmp_token->next->type == LABEL)
		ldi_error(NULL, nb, 1);
	if (tmp_token->next->type != REG)
		ldi_error(tmp_token->next->name, nb, 0);
	code += 4;
	tmp_token = tmp_token->next->next;
	if (tmp_token && tmp_token->type != OP && tmp_token->type != LABEL)
		ldi_error(NULL, nb, 0);
	return (code);
}

void	ldi(t_token *tmp_token, t_asm *head, int nb)
{
	int		n;
	t_token	*op;

	op = tmp_token;
	hex_con(nb, 1, head);
	hex_con(arg_cod_ldi(tmp_token->next, nb), 1, head);
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == IND)
		n = ft_atoi(tmp_token->next->name);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else if (tmp_token->next->type == IND_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	tmp_token->next->type == REG ? hex_con(n, 1, head) : hex_con(n, 2, head);
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	tmp_token->next->type == REG ? hex_con(n, 1, head) : hex_con(n, 2, head);
	n = ft_atoi(tmp_token->next->next->name + 1);
	hex_con(n, 1, head);
}
