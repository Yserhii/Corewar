/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:39:15 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/10 13:39:16 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 's' || file[i - 2] != '.')
		error("Usage: ./asm <sourcefile.s>\n", NULL);
}

int		empty_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n' || line[i] == '#')
		return (1);
	while (line[++i])
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '	')
			return (0);
	return (1);
}

int		check_line(char *line)
{
	if (empty_line(line))
		return (1);
	if (ft_strstr(line, NAME_CMD_STRING) || ft_strstr(line, COMMENT_CMD_STRING))
		return (1);
	else
		return (0);
	return (1);
}

int		is_label(char *line)
{
	int	i;

	i = -1;
	if (ft_strchr(line, LABEL_CHAR) == NULL)
		return (0);
	while (line[++i] == ' ' || line[i] == '\t')
		;
	while (line[i] != LABEL_CHAR)
	{
		if (ft_strchr(LABEL_CHARS, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

int		check_dir_reg(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			error("invalid register/direct ", str);
		i++;
	}
	return (1);
}
