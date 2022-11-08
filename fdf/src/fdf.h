/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:42:45 by greita            #+#    #+#             */
/*   Updated: 2022/03/14 08:13:01 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0080FF
# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define GREY 0x101010
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_LESS 43
# define KEY_MORE 47
# define KEY_LBRACKET 33
# define KEY_RBRACKET 30
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_C 8

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars
{
	t_img	*img;
	void	*mlx;
	void	*mlx_win;
	int		fd;
	int		map_width;
	int		map_height;
	int		**alts;
	int		trans_x;
	int		trans_y;
	int		color;
	int		temp_x;
	int		temp_y;
	float	zoom;
	float	alt_zoom;
	float	x1;
	float	y1;
	float	z1;
	float	x2;
	float	y2;
	float	z2;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_vars;

typedef struct s_parse
{
	char	*line;
	char	**nums;
	int		is_first_elem;
	int		words_amount;
	int		prev_words_amount;
	int		line_num;
	int		word_num;
	char	*temp_str;
}	t_parse;

/*parser.c*/
void	ft_parser(t_vars *vars, t_parse *temps, char *path);
/*keyhook.c*/
int		ft_keyhook(int keycode, t_vars *vars);
/*draw.c*/
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_win_close(t_vars *vars);
void	ft_clear_map(t_vars *vars);
void	ft_draw_map(t_vars *vars);
void	ft_print_help(t_vars *vars);
/*drawline.c*/
void	ft_draw_line(t_vars *vars, t_img *img);
/*draw_utils.c*/
float	ft_degtorad(int deg);
float	ft_get_maxmod(float num1, float num2);
int		ft_get_zoom(int map_width, int map_height);
/*parser_utils.c*/
void	ft_error(char *message);
void	ft_open_map(t_vars *vars, char *path);
int		ft_item_counter(char **arr);
void	ft_close(int fd);
void	ft_free_arr(void **arr);
/*keyhook_utils.c*/
int		ft_is_keycode(int code);
void	ft_change_color(t_vars *vars);

#endif
