/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:12:36 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 11:05:26 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	*free_2d_array(t_point **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free (map);
	return (NULL);
}

void	*free_2d_array_char(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

int	free_and_exit(t_env *env)
{
	if (env->map)
		free_2d_array(env->map);
	if (env->mlx)
	{
		mlx_destroy_image(env->mlx, env->img.img);
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	exit (EXIT_SUCCESS);
	return (0);
}

void	free_invalid_map(int fd, t_point **map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free_2d_array(map);
}
