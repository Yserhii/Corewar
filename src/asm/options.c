/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:20:45 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 13:20:47 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	cod_operetion(char *op, t_asm *head)
{
	if (ft_strequ(op, "ld") || ft_strequ(op, "st") ||
		ft_strequ(op, "sub") || ft_strequ(op, "add") ||
		ft_strequ(op, "and") || ft_strequ(op, "or") ||
		ft_strequ(op, "sti") || ft_strequ(op, "xor") ||
		ft_strequ(op, "lld") || ft_strequ(op, "ldi") ||
		ft_strequ(op, "lldi") || ft_strequ(op, "aff"))
		head->b_pos++;
	else if (!ft_strequ(op, "live") && !ft_strequ(op, "zjmp") &&
			!ft_strequ(op, "fork") && !ft_strequ(op, "lfork"))
		error("Invalid instruction", op);
}

char	*name_operation(char **str)
{
	char	*res;
	char	*tmp;

	res = what_op(*str);
	if (res == NULL)
		error("Invalid instruction", *str);
	tmp = *str;
	if (*(tmp + ft_strlen(res)) != ' ' && *(tmp + ft_strlen(res))
	!= DIRECT_CHAR && *(tmp + ft_strlen(res)) != '\t')
		error("Syntax error", *str);
	*str = ft_strdup(*str + ft_strlen(res));
	return (res);
}

void	del_comment(char **line)
{
	char	*del;

	if (!ft_strchr(*line, COMMENT_CHAR) && !ft_strchr(*line, ALT_COMMENT_CHAR))
		return ;
	if ((*line)[0] == COMMENT_CHAR || (*line)[0] == ALT_COMMENT_CHAR)
		g_new_line = 1;
	if (ft_strchr(*line, COMMENT_CHAR))
	{
		del = *line;
		*line = ft_strndup(*line, ft_strchr(*line, COMMENT_CHAR) - *line);
		free(del);
	}
	else
	{
		del = *line;
		*line = ft_strndup(*line, ft_strchr(*line, ALT_COMMENT_CHAR) - *line);
		free(del);
	}
}

void	check_code_line(char *line)
{
	if (ft_strchr(line, SEPARATOR_CHAR))
	{
		if (empty_line(ft_strrchr(line, SEPARATOR_CHAR)))
			error("Syntax error", line);
	}
}

int		check_ind(char *line)
{
	if (!*line)
		error("Syntax error", line);
	if (line[0] == '-')
	{
		if (!ft_allnum(line + 1) || line[1] == '\0')
			error("Bad argument", line);
	}
	else
	{
		if (!ft_allnum(line))
			error("Bad argument", line);
	}
	return (1);
}
