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

void	new_file(t_asm *head, char *file)
{
	char	*name;
	// char	*del;
	int		i;
	int		j;

	j = ft_strrchr(file, '.') - file + 1;
	name = ft_strnew(j);
	i = 0;
	while (file[i] && i != j)
	{
		name[i] = file[i];
		i++;
	}
	// del = name;
	name = ft_strjoin(name, "cor");
	// free(del);
	head->fd_cor = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	// записать magic header
}

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

void	check_name(char	*line, t_asm *head)
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
	if (ft_strstr(line, NAME_CMD_STRING))
		check_name(line);
	// else if (ft_strstr(line, COMMENT_CMD_STRING))
		// check_comment(line);
	else
		return (0);
	return (1);
}

void	give_name_comment(t_asm *head)
{
	char	*line;

	get_next_line(head->fd_s, &line);
	check_line(line);
	// while (get_next_line(head->fd_s, &line) && check_line(line))
	// {
	// 	if (ft_strstr())
	// }
}
