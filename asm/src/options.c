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

	res = NULL;
	if (ft_strnequ(*str, "ld", 2))
		res = ft_strdup("ld");
	else if (ft_strnequ(*str, "st", 2))
		res = ft_strdup("st");
	else if (ft_strnequ(*str, "sub", 3))
		res = ft_strdup("sub");
	else if (ft_strnequ(*str, "sti", 3))
		res = ft_strdup("sti");
	else if (ft_strnequ(*str, "and", 3))
		res = ft_strdup("and");
	else if (ft_strnequ(*str, "aff", 3))
		res = ft_strdup("aff");
	else if (ft_strnequ(*str, "ldi", 3))
		res = ft_strdup("ldi");
	else if (ft_strnequ(*str, "xor", 3))
		res = ft_strdup("xor");
	else if (ft_strnequ(*str, "or", 2))
		res = ft_strdup("or");
	else if (ft_strnequ(*str, "fork", 4))
		res = ft_strdup("fork");
	else if (ft_strnequ(*str, "lldi", 4))
		res = ft_strdup("lldi");
	else if (ft_strnequ(*str, "lld", 3))
		res = ft_strdup("lld");
	else if (ft_strnequ(*str, "lfork", 5))
		res = ft_strdup("lfork");
	else if (ft_strnequ(*str, "live", 4))
		res = ft_strdup("live");
	else if (ft_strnequ(*str, "add", 3))
		res = ft_strdup("add");
	else if (ft_strnequ(*str, "zjmp", 4))
		res = ft_strdup("zjmp");
	else
		error("Invalid instruction", *str);
	tmp = *str;
	if (*(tmp + ft_strlen(res)) != ' ' && *(tmp + ft_strlen(res))
	!= DIRECT_CHAR && *(tmp + ft_strlen(res)) != '	')
		error("Syntax error\n", NULL);
	*str = ft_strdup(*str + ft_strlen(res));
	return (res);
}

void	del_comment(char **line)
{
	char	*del;

	if (!ft_strchr(*line, COMMENT_CHAR) && !ft_strchr(*line, ALT_COMMENT_CHAR))
		return ;
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
			error("Syntax error\n", NULL);
	}
}

int		check_ind(char *line)
{
	if (!*line)
		error("Syntax error\n", NULL);
	if (ft_allnum(line))
		error("Bad argument", line);
	return (1);
}
