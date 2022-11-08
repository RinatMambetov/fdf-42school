/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:41:58 by greita            #+#    #+#             */
/*   Updated: 2022/03/14 08:09:29 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_keycode(int code)
{
	return (code == KEY_UP || code == KEY_DOWN
		|| code == KEY_LEFT || code == KEY_RIGHT
		|| code == KEY_LESS || code == KEY_MORE
		|| code == KEY_LBRACKET || code == KEY_RBRACKET || code == KEY_C
		|| code == KEY_W || code == KEY_S || code == KEY_D || code == KEY_A
		|| code == KEY_1 || code == KEY_2 || code == KEY_3
		|| code == KEY_4 || code == KEY_5 || code == KEY_6);
}

void	ft_change_color(t_vars *vars)
{
	static int	code = 0;

	code++;
	if (code == 1)
		vars->color = RED;
	if (code == 2)
		vars->color = GREEN;
	if (code == 3)
		vars->color = BLUE;
	if (code == 4)
	{
		vars->color = WHITE;
		code = 0;
	}
}
