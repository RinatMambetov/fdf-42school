/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:43:39 by greita            #+#    #+#             */
/*   Updated: 2022/03/16 21:13:12 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_vars *vars)
{
	vars->x1 = vars->x1 * cos(vars->angle_y) + vars->z1 * sin(vars->angle_y);
	vars->x2 = vars->x2 * cos(vars->angle_y) + vars->z2 * sin(vars->angle_y);
	vars->y1 = vars->y1 * cos(vars->angle_x) - vars->z1 * sin(vars->angle_x);
	vars->y2 = vars->y2 * cos(vars->angle_x) - vars->z2 * sin(vars->angle_x);
}

void	ft_isometric(t_vars *vars)
{
	vars->x1 = vars->x1 * cos(vars->angle_z) - vars->y1 * sin(vars->angle_z);
	vars->x2 = vars->x2 * cos(vars->angle_z) - vars->y2 * sin(vars->angle_z);
	vars->y1 = vars->x1 * sin(vars->angle_z) + vars->y1 * cos(vars->angle_z);
	vars->y2 = vars->x2 * sin(vars->angle_z) + vars->y2 * cos(vars->angle_z);
}

void	ft_transform_coords(t_vars *vars)
{
	vars->z1 = vars->alts[(int)vars->y1][(int)vars->x1] * vars->alt_zoom;
	vars->z2 = vars->alts[(int)vars->y2][(int)vars->x2] * vars->alt_zoom;
	vars->x1 = (vars->x1 - vars->map_width / 2) * vars->zoom;
	vars->x2 = (vars->x2 - vars->map_width / 2) * vars->zoom;
	vars->y1 = (vars->y1 - vars->map_height / 2) * vars->zoom;
	vars->y2 = (vars->y2 - vars->map_height / 2) * vars->zoom;
	ft_rotate(vars);
	ft_isometric(vars);
	vars->x1 += vars->trans_x;
	vars->x2 += vars->trans_x;
	vars->y1 += vars->trans_y;
	vars->y2 += vars->trans_y;
}

void	ft_draw_line(t_vars *vars, t_img *img)
{
	float	dx;
	float	dy;
	float	max;

	ft_transform_coords(vars);
	dx = vars->x2 - vars->x1;
	dy = vars->y2 - vars->y1;
	max = ft_get_maxmod(dx, dy);
	dx /= max;
	dy /= max;
	while ((int)(vars->x2 - vars->x1) || (int)(vars->y2 - vars->y1))
	{
		ft_mlx_pixel_put(img, vars->x1, vars->y1, vars->color);
		vars->x1 += dx;
		vars->y1 += dy;
	}
}
