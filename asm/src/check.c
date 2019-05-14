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
		if (line[i] != '\n' && line[i] != ' ')
			return (0);
	return (1);
}

void	check_name_comment(char	*line, t_asm *head)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_strncmp(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		error("Syntax error", line);
	i += ft_strlen(NAME_CMD_STRING);
	while (line [i] && line[i] == ' ')
		i++;
	if (line[i] != '"')
		error("Syntax error", line);
	while (line[++i] && line[i] != '"')
		;
	if (line[i] == '\0')
	{
		free(line);
		get_next_line(head->fd_s, &line);
		i = 0;
		while (line[++i] && line[i] != '"')
		;
	}
	if (line[i] != '"')
		error("Syntax error", line);
	while (line [++i] && line[i] == ' ')
		;
	if (line[i] != '\0')
		error("Sy2ntax error", line);
}

int		check_line(char	*line)
{
	if (empty_line(line))
		return (1);
	if (ft_strstr(line, NAME_CMD_STRING) || ft_strstr(line, COMMENT_CMD_STRING))
		return (1);
	else
		return (0);
	return (1);
}

char	*save_name(char *line, t_asm *head)
{
	int		i;
	int		j;

	head->name = ft_strnew(PROG_NAME_LENGTH);
	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (ft_strncmp(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		error("Syntax error", line);
	i += ft_strlen(NAME_CMD_STRING);
	while (line[i] && line[i] != '"')
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
		i++;
	}
	while (line[++i] != '"')
	{
		if (line[i] == '\0')
		{
			free(line);
			get_next_line(head->fd_s, &line);
			head->name[j++] = '\n';
			i = 0;
		}
		head->name[j] = line[i];
		j++;
	}
	while (line [++i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
	}
	return (line);
}

char	*save_comment(char *line, t_asm *head)
{
	int		i;
	int		j;

	head->comment = ft_strnew(COMMENT_LENGTH);
	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (ft_strncmp(line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		error("Syntax error", line);
	i += ft_strlen(COMMENT_CMD_STRING);
	while (line[i] && line[i] != '"')
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
		i++;
	}
	while (line[++i] != '"')
	{
		if (line[i] == '\0')
		{
			free(line);
			get_next_line(head->fd_s, &line);
			head->comment[j++] = '\n';
			i = 0;
		}
		head->comment[j] = line[i];
		j++;
	}
	while (line [++i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
	}
	return (line);
}

char	*read_name_comment(t_asm *head)
{
	char	*line;

	while (get_next_line(head->fd_s, &line) && check_line(line))
	{
		if (ft_strstr(line, NAME_CMD_STRING))
			line = save_name(line, head);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			save_comment(line, head);
		free(line);
	}
	printf("[%s]\n[%s]\n", head->name, head->comment);
	return (line);
}
