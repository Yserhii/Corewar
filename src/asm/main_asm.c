/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:13:44 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/10 13:13:46 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	new_file(t_asm *head, char *file)
{
	char	*name;
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
	name = ft_strjoin(name, "cor");
	head->fd_cor = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_printf("{green}Writing output program to %s{eoc}\n", name);
	free(name);
}

void	error(char *str, char *line)
{
	if (line == NULL)
		ft_printf("{red}%s", str);
	else
		ft_printf("{red}%s [%s]{eoc}\n", str, line);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_asm	head;

	g_new_line = 0;
	head.f = NULL;
	head.token = NULL;
	head.b_pos = 0;
	head.label = NULL;
	if (argc != 2)
		exit(ft_printf("{cyan}Usage: ./asm <sourcefile.s>{eoc}\n"));
	check_file(argv[1]);
	head.fd_s = open(argv[1], O_RDONLY);
	parse_code(&head, read_name_comment(&head));
	if (g_new_line == 0)
		error("Syntax error\n", NULL);
	valid_code(&head);
	new_file(&head, argv[1]);
	write_file(&head);
	code_to_hex(&head);
	return (0);
}
