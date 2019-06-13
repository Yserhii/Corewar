/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:11:55 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/29 15:11:57 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

char	*what_op2(char *str)
{
	if (ft_strnequ(str, "or", 2))
		return (ft_strdup("or"));
	else if (ft_strnequ(str, "fork", 4))
		return (ft_strdup("fork"));
	else if (ft_strnequ(str, "lldi", 4))
		return (ft_strdup("lldi"));
	else if (ft_strnequ(str, "lld", 3))
		return (ft_strdup("lld"));
	else if (ft_strnequ(str, "lfork", 5))
		return (ft_strdup("lfork"));
	else if (ft_strnequ(str, "live", 4))
		return (ft_strdup("live"));
	else if (ft_strnequ(str, "add", 3))
		return (ft_strdup("add"));
	else if (ft_strnequ(str, "zjmp", 4))
		return (ft_strdup("zjmp"));
	else
		return (NULL);
}

char	*what_op(char *str)
{
	if (ft_strnequ(str, "ldi", 3))
		return (ft_strdup("ldi"));
	else if (ft_strnequ(str, "ld", 2))
		return (ft_strdup("ld"));
	else if (ft_strnequ(str, "sti", 3))
		return (ft_strdup("sti"));
	else if (ft_strnequ(str, "st", 2))
		return (ft_strdup("st"));
	else if (ft_strnequ(str, "sub", 3))
		return (ft_strdup("sub"));
	else if (ft_strnequ(str, "and", 3))
		return (ft_strdup("and"));
	else if (ft_strnequ(str, "aff", 3))
		return (ft_strdup("aff"));
	else if (ft_strnequ(str, "xor", 3))
		return (ft_strdup("xor"));
	else
		return (what_op2(str));
}
