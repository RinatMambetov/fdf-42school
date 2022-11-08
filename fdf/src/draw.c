/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:49:42 by greita            #+#    #+#             */
/*   Updated: 2022/03/14 08:09:16 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	ft_free_arr((void **)vars->alts);
	exit(EXIT_SUCCESS);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_WIDTH && x > 0 && y < WIN_HEIGHT && y > 0)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_clear_map(t_vars *vars)
{
	vars->temp_y = 0;
	while (vars->temp_y < WIN_HEIGHT)
	{
		vars->temp_x = 0;
		while (vars->temp_x < WIN_WIDTH)
		{
			ft_mlx_pixel_put(vars->img, vars->temp_x, vars->temp_y, GREY);
			vars->temp_x++;
		}
		vars->temp_y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
}

void	ft_draw_map(t_vars *vars)
{
	vars->temp_y = -1;
	while (++vars->temp_y < vars->map_height)
	{
		vars->temp_x = -1;
		while (++vars->temp_x < vars->map_width)
		{
			if (vars->temp_x < vars->map_width - 1)
			{
				vars->x1 = vars->temp_x;
				vars->y1 = vars->temp_y;
				vars->x2 = vars->temp_x + 1;
				vars->y2 = vars->temp_y;
				ft_draw_line(vars, vars->img);
			}
			if (vars->temp_y < vars->map_height - 1)
			{
				vars->x1 = vars->temp_x;
				vars->y1 = vars->temp_y;
				vars->x2 = vars->temp_x;
				vars->y2 = vars->temp_y + 1;
				ft_draw_line(vars, vars->img);
			}
		}
	}
}

void	ft_print_help(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 10, YELLOW,
		"translate: up down left right");
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 30, YELLOW,
		"rotate: w s a d");
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 50, YELLOW,
		"projection: 1 - 6");
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 70, YELLOW,
		"altitude: [ ]");
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 90, YELLOW,
		"zoom: < >");
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 110, YELLOW,
		"color: c");
}
