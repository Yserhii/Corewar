/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:15:08 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:15:10 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	valid_sti(t_token *token)
{
	token = token->next;
	if (token->type != REG)
		error("Bad argument for sti", token->name);
	token = token->next;
	if (!token || token->type == OP || token->type == LABEL)
		error("Too few argumentd for sti", NULL);
	token = token->next;
	if (!token || token->type == OP || token->type == LABEL)
		error("Too few argumentd for sti", NULL);
	if (token->type != REG && token->type != DIR && token->type != DIR_L)
		error("Bad argument for sti", token->next->name);
	token = token->next;
	if (token && token->type != OP && token->type != LABEL)
		error("Too many arguments for sti\n", NULL);
}

int		arg_code_sti(t_token *token, int code)
{
	code += 64;
	token = token->next->next;
	if (token->type == REG)
		code += 16;
	else if (token->type == DIR || token->type == DIR_L)
		code += 32;
	else if (token->type == IND || token->type == IND_L)
		code += 48;
	token = token->next;
	if (token->type == REG)
		code += 4;
	else if (token->type == DIR || token->type == DIR_L)
		code += 8;
	return (code);
}

void	sti(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	op = tmp_token;
	hex_con(11, 1, head);
	hex_con(arg_code_sti(tmp_token, 0), 1, head);
	n = ft_atoi(tmp_token->next->name + 1);
	hex_con(n, 1, head);
	tmp_token = tmp_token->next->next;
	if (tmp_token->type == REG)
		n = ft_atoi(tmp_token->name + 1);
	if (tmp_token->type == DIR)
		n = ft_atoi(tmp_token->name + 1);
	if (tmp_token->type == IND)
		n = ft_atoi(tmp_token->name);
	if (tmp_token->type == DIR_L)
		n = label_pos(head, tmp_token->name + 1) - op->pos;
	if (tmp_token->type == IND_L)
		n = label_pos(head, tmp_token->name) - op->pos;
	tmp_token->type == REG ? hex_con(n, 1, head) : hex_con(n, 2, head);
	if (tmp_token->next->type == REG || tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	tmp_token->next->type == REG ? hex_con(n, 1, head) : hex_con(n, 2, head);
}
