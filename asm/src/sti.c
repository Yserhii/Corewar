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

int		arg_code_sti(t_token *tmp_token)
{
	int		code;
	t_token	*token;

	code = 0;
	token = tmp_token->next;
	if (token->type != REG)
		error("Bat argument for operation sti", token->name);
	code += 64;
	token = token->next;
	if (token->type == REG)
		code += 16;
	else if (token->type == DIR || token->type == DIR_L)
		code += 32;
	else if (token->type == IND || token->type == IND_L)
		code += 48;
	else
		error("Bat argument for operation sti", token->name);
	if (token->next->type == REG)
		code += 4;
	else if (token->next->type == DIR || token->next->type == DIR_L)
		code += 8;
	else
		error("Bat argument for operation sti", token->next->name);
	return (code);
}

void	sti(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	op = tmp_token;
	hex_con(11, 1, head);
	hex_con(arg_code_sti(tmp_token), 1, head);
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
