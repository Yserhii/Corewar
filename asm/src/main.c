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

void	error(char *str)
{
	ft_printf("%s", str);
	exit (0);
}

int		main(int argc, char **argv)
{
	t_asm	*head;

	head = ft_memalloc(sizeof(t_asm));
	if (argc != 2)
		error("Usage: ./asm <sourcefile.s>\n");
	check_file(argv[1]);
	head->fd_s = open(argv[1], O_RDONLY);
	new_file(head, argv[1]);
	give_name(head);
	return (0);
}
