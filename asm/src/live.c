/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:13:53 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:13:56 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	live(t_token *tmp_token, t_asm *head)
{
	int		n;
	t_token	*op;

	n = 5;
	op = tmp_token;
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name + 1);
	else if (tmp_token->next->type == DIR_L)
		n = label_pos(head, tmp_token->next->name + 1) - op->pos;
	else
		error("Bat argument for operation live", tmp_token->next->name);
	hex_con(1, 1, head);
	hex_con(n, 4, head);
}
