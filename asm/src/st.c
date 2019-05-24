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

void	second_arg(t_token *op, t_token *tmp_token, t_asm *head, int n)
{
	tmp_token = tmp_token->next;
	if (tmp_token->next->type == REG)
	{
		n = ft_atoi(tmp_token->next->name + 1);
		hex_con(n, 1, head);
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
		error("Bat argument for operation st", tmp_token->next->name);
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
	printf("->%d\n", n);
	hex_con(n, 1, head);
	if (tmp_token->next->type != REG)
		error("Bat argument for operation st", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	hex_con(n, 1, head);
	second_arg(op, tmp_token, head, n);
}
