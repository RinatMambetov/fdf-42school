/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:49:13 by greita            #+#    #+#             */
/*   Updated: 2022/03/16 21:01:16 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_keycode_transform(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP)
		vars->trans_y -= 10;
	if (keycode == KEY_DOWN)
		vars->trans_y += 10;
	if (keycode == KEY_LEFT)
		vars->trans_x -= 10;
	if (keycode == KEY_RIGHT)
		vars->trans_x += 10;
	if (keycode == KEY_W)
		vars->angle_x += ft_degtorad(5);
	if (keycode == KEY_S)
		vars->angle_x -= ft_degtorad(5);
	if (keycode == KEY_D)
		vars->angle_y += ft_degtorad(5);
	if (keycode == KEY_A)
		vars->angle_y -= ft_degtorad(5);
}

void	ft_check_keycode_zoom(int keycode, t_vars *vars)
{
	if (keycode == KEY_LESS)
	{
		vars->zoom *= 0.9;
		vars->alt_zoom *= 0.9;
	}
	if (keycode == KEY_MORE)
	{
		vars->zoom *= 1.1;
		vars->alt_zoom *= 1.1;
	}
	if (keycode == KEY_LBRACKET)
		vars->alt_zoom *= 0.8;
	if (keycode == KEY_RBRACKET)
		vars->alt_zoom *= 1.2;
}

void	ft_check_keycode_projection1(int keycode, t_vars *vars)
{
	if (keycode == KEY_1)
	{
		vars->angle_x = ft_degtorad(25);
		vars->angle_y = ft_degtorad(-30);
		vars->angle_z = ft_degtorad(20);
	}
	if (keycode == KEY_2)
	{
		vars->angle_x = 0;
		vars->angle_y = 0;
		vars->angle_z = 0;
	}
	if (keycode == KEY_3)
	{
		vars->angle_x = 0;
		vars->angle_y = ft_degtorad(90);
		vars->angle_z = 0;
	}
}

void	ft_check_keycode_projection2(int keycode, t_vars *vars)
{
	if (keycode == KEY_4)
	{
		vars->angle_x = 0;
		vars->angle_y = ft_degtorad(270);
		vars->angle_z = 0;
	}
	if (keycode == KEY_5)
	{
		vars->angle_x = ft_degtorad(270);
		vars->angle_y = ft_degtorad(360);
		vars->angle_z = ft_degtorad(360);
	}
	if (keycode == KEY_6)
	{
		vars->angle_x = ft_degtorad(90);
		vars->angle_y = ft_degtorad(360);
		vars->angle_z = ft_degtorad(360);
	}
}

int	ft_keyhook(int keycode, t_vars *vars)
{
	ft_check_keycode_transform(keycode, vars);
	ft_check_keycode_zoom(keycode, vars);
	ft_check_keycode_projection1(keycode, vars);
	ft_check_keycode_projection2(keycode, vars);
	if (keycode == KEY_C)
		ft_change_color(vars);
	if (ft_is_keycode(keycode))
	{
		ft_clear_map(vars);
		ft_draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
		ft_print_help(vars);
	}
	if (keycode == KEY_ESC)
		ft_win_close(vars);
	return (0);
}
