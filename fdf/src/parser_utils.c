/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:43:31 by greita            #+#    #+#             */
/*   Updated: 2022/03/14 08:09:06 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror("Error (wrong close fd)");
}

int	ft_item_counter(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_open_map(t_vars *vars, char *path)
{
	vars->fd = open(path, O_RDONLY);
	if (vars->fd == -1)
	{
		perror("Error (wrong open file)");
		exit(EXIT_FAILURE);
	}
}

void	ft_free_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
