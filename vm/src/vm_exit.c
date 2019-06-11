/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:51:55 by yserhii           #+#    #+#             */
/*   Updated: 2019/06/09 11:51:58 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_exit_bot(int n, t_bot *bot)
{
	(void)n;
	(void)bot;
	// if (n == 1)
	// 	ft_printf("{red}Exec code differs from his size, bot id = [%d]{eoc}\n",
	// 				bot->id);
	// else if (n == 2)
	// 	ft_printf("{red}Invalid commet, bot id = [%d]{eoc}\n", bot->id);
	// else if (n == 3)
	// 	ft_printf("{red}Not NULL after name bot, bot id = [%d]{eoc}\n",
	// 				bot->id);
	// else if (n == 4)
	// 	ft_printf("{red}Exec code not valid size = [%d], bot id = [%d]{eoc}\n",
	// 				bot->size, bot->id);
	// else if (n == 5)
	// 	ft_printf("{red}Invalid name, bot id = [%d]{eoc}\n", bot->id);
	// else if (n == 6)
	// 	ft_printf("{red}Invalid magic header, bot id = [%d]{eoc}\n", bot->id);
	exit(1);
}

void	vm_exit(int n)
{
	(void)n;
	// if (n == 1)
	// 	ft_printf("{red}Not valid number cycles, number must be >= 0{eoc}\n");
	// else if (n == 2)
	// 	ft_printf("{red}Not valid file with bot (*.cor){eoc}\n");
	// else if (n == 3)
	// {
	// 	ft_printf("{red}Not valid file with bot (*.cor) ");
	// 	ft_printf("or you use two identical id players{eoc}\n");
	// }
	// else if (n == 4)
	// 	ft_printf("{red}Id players must be int from 1 to 4{eoc}\n");
	// else if (n == 5)
	// 	ft_printf("{red}Verbosity levels are only 2, 4, 8, 16 or 30{eoc}\n");
	// else if (n == 6)
	// 	ft_printf("{red}Not valid file with bot (*.cor){eoc}\n");
	// else if (n == 7)
	// 	ft_printf("{red}You give so many players{eoc}\n");
	// else if (n == 8)
	// 	ft_printf("{red}You give not valid arguments use [--help]{eoc}\n");
	// else if (n == 9)
	// 	ft_printf("{red}Malloc error{eoc}\n");
	// else if (n == 10)
	// 	ft_printf("{red}Can't read file with bot{eoc}\n");
	exit(1);
}
