/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:43:17 by greita            #+#    #+#             */
/*   Updated: 2022/03/13 21:47:56 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initvars(t_vars *vars)
{
	vars->trans_x = WIN_WIDTH / 2;
	vars->trans_y = WIN_HEIGHT / 2;
	vars->alt_zoom = 2;
	vars->angle_x = ft_degtorad(25);
	vars->angle_y = ft_degtorad(-30);
	vars->angle_z = ft_degtorad(20);
	vars->zoom = ft_get_zoom(vars->map_width, vars->map_height);
	vars->color = WHITE;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_img	img;
	t_parse	temps;

	if (argc != 2)
		ft_error("Error: wrong amount of arguments");
	ft_parser(&vars, &temps, argv[1]);
	ft_initvars(&vars);
	vars.img = &img;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "greita");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	ft_clear_map(&vars);
	ft_draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_hook(vars.mlx_win, 2, 1L << 0, ft_keyhook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_win_close, &vars);
	ft_print_help(&vars);
	mlx_loop(vars.mlx);
	ft_free_arr((void **)vars.alts);
	return (0);
}
