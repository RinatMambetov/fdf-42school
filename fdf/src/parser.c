/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:47:26 by greita            #+#    #+#             */
/*   Updated: 2022/03/13 21:47:55 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_words_amount(t_parse *temps)
{
	if (temps->is_first_elem)
	{
		temps->prev_words_amount = temps->words_amount;
		temps->is_first_elem = 0;
	}
	if (temps->words_amount != temps->prev_words_amount)
		ft_error("Error: different length of lines");
}

void	ft_get_mapsize(t_vars *vars, t_parse *temps)
{
	vars->map_height = 0;
	temps->is_first_elem = 1;
	temps->line = ft_get_nextline(vars->fd);
	while (temps->line)
	{
		vars->map_height++;
		temps->temp_str = temps->line;
		temps->line = ft_strtrim(temps->line, "\32\t\n");
		if (!temps->line)
			ft_error("Error: (wrong trim str)");
		temps->nums = ft_split(temps->line, ' ');
		if (!temps->nums)
			ft_error("Error: (wrong split str)");
		temps->words_amount = ft_item_counter(temps->nums);
		ft_check_words_amount(temps);
		free(temps->line);
		free(temps->temp_str);
		ft_free_arr((void **)temps->nums);
		temps->line = ft_get_nextline(vars->fd);
		temps->prev_words_amount = temps->words_amount;
	}
	free(temps->line);
	vars->map_width = temps->words_amount;
}

void	ft_get_altitudes(t_vars *vars, t_parse *temps)
{
	vars->alts = malloc(sizeof(int *) * (vars->map_height + 1));
	if (!vars->alts)
		ft_error("Error: wrong malloc for altitudes");
	temps->line_num = 0;
	while (temps->line_num < vars->map_height)
	{
		temps->line = ft_get_nextline(vars->fd);
		temps->nums = ft_split(temps->line, ' ');
		if (!temps->nums)
			ft_error("Error: wrong split str");
		temps->word_num = 0;
		vars->alts[temps->line_num] = malloc(sizeof(int) * vars->map_width);
		if (!vars->alts[temps->line_num])
			ft_error("Error: wrong malloc for altitudes[item]");
		while (temps->word_num < vars->map_width)
		{
			vars->alts[temps->line_num][temps->word_num]
				= ft_atoi(temps->nums[temps->word_num]);
			temps->word_num++;
		}
		free(temps->line);
		ft_free_arr((void **)temps->nums);
		temps->line_num++;
	}
	vars->alts[temps->line_num] = NULL;
}

void	ft_parser(t_vars *vars, t_parse *temps, char *path)
{
	ft_open_map(vars, path);
	ft_get_mapsize(vars, temps);
	if (!vars->map_height && !vars->map_width)
		ft_error("Error: empty map");
	ft_close(vars->fd);
	ft_open_map(vars, path);
	ft_get_altitudes(vars, temps);
	ft_close(vars->fd);
}
