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

void	valid_ldi(t_token *token, int nb, t_asm *head)
{
	token = token->next;
	token->type == DIR_L ? label_pos(head, token->name + 1) : 0;
	token->type == IND_L ? label_pos(head, token->name) : 0;
	token = token->next;
	if (!token || token->type == OP || token->type == LABEL)
		ldi_error(NULL, nb, 1);
	if (token->type != REG && token->type != DIR && token->type != DIR_L)
		ldi_error(token->name, nb, 0);
	token->type == DIR_L ? label_pos(head, token->name + 1) : 0;
	token = token->next;
	if (!token || token->type == OP || token->type == LABEL)
		ldi_error(NULL, nb, 1);
	if (token->type != REG)
		ldi_error(token->name, nb, 0);
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		ldi_error(NULL, nb, 0);
}

int		arg_cod_ldi(t_token *tmp_token, int code)
{
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 128;
	else if (tmp_token->type == REG)
		code += 64;
	else if (tmp_token->type == IND || tmp_token->type == IND_L)
		code += 192;
	tmp_token = tmp_token->next;
	if (tmp_token->type == REG)
		code += 16;
	else if (tmp_token->type == DIR || tmp_token->type == DIR_L)
		code += 32;
	code += 4;
	return (code);
}

void	ldi(t_token *tmp_token, t_asm *head, int nb)
{
	int		n;
	t_token	*op;

	op = tmp_token;
	hex_con(nb, 1, head);
	hex_con(arg_cod_ldi(tmp_token->next, 0), 1, head);
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == IND)
		n = ft_atoi(tmp_token->next->name);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else if (tmp_token->next->type == IND_L)
		n = label_pos(head, tmp_token->next->name) - op->pos;
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
