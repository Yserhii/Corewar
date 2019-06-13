/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:06:07 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/29 16:06:08 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <ncurses.h>
# include <vm.h>

typedef struct		s_vis
{
	WINDOW		*map;
	WINDOW		*menu;
}					t_vis;

#endif
