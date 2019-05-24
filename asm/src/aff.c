/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:12:25 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:28 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	aff(t_token *tmp_token, t_asm *head)
{
	int	n;

	hex_con(16, 1, head);
	hex_con(64, 1, head);
	if (tmp_token->next->type != REG)
		error("Bat argument for operation aff", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	hex_con(n, 1, head);
}
