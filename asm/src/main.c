/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:13:44 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/10 13:13:46 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	error(char *str, char *line)
{
	if (line == NULL)
		ft_printf("%s", str);
	else
		ft_printf("%s [%s]\n", str, line);
	exit (0);
}

int		main(int argc, char **argv)
{
	t_asm	head;

	if (argc != 2)
		error("Usage: ./asm <sourcefile.s>\n", NULL);
	check_file(argv[1]);
	head->fd_s = open(argv[1], O_RDONLY);
	new_file(&head, argv[1]);
	give_name_comment(&head);
	return (0);
}
