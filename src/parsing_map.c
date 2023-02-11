/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:28:01 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 11:06:24 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static	t_point	*malloc_line(char	**line, int	*len, int *x, t_env *env)
{
	t_point	*map;

	*len = 0;
	*x = 0;
	while (line[*len])
		*len += 1;
	if (env->column == 0)
		env->column = *len;
	if (env->column != *len)
	{
		ft_putstr_fd("invalid map\n", 2);
		return (NULL);
	}
	map = malloc(*len * sizeof(t_point));
	return (map);
}

static t_point	*set_point_coordinates(t_env *env, char **l, float y)
{
	int			x;
	int			length;
	t_point		*map;
	char		**line_color;

	map = malloc_line(l, &length, &x, env);
	if (!map)
		return (NULL);
	while (x < length - 1)
	{
		if (ft_strchr(l[x], ',') != 0)
		{
			line_color = ft_split(l[x], ',');
			if (!line_color)
				free_and_exit(env);
			map[x].z = ft_atoi(line_color[0]);
			free_2d_array_char(line_color);
		}
		else
			map[x].z = ft_atoi(l[x]);
		map[x] = parsing_rotate(map[x], y, x, env);
		x++;
	}
	return (map);
}

static t_point	*split_and_malloc_line(t_env *env, float y, char *line)
{
	t_point	*map;
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (!split_line)
		exit (EXIT_FAILURE);
	map = set_point_coordinates(env, split_line, y);
	free_2d_array_char(split_line);
	free(line);
	return (map);
}

static t_point	**malloc_2d_map(t_env *env, char *map_txt)
{
	t_point	**map;

	env->row = count_row(map_txt);
	map = malloc((env->row + 1) * sizeof(t_point *));
	if (!map)
		free_and_exit(env);
	return (map);
}

t_point	**parsing_map(char *map_txt, t_env *env)
{
	t_point	**map;
	int		fd;
	int		x;
	char	*line;
	float	y;

	x = 0;
	y = 0;
	map = malloc_2d_map(env, map_txt);
	fd = open(map_txt, O_RDONLY);
	line = get_next_line(fd);
	env->column = 0;
	while (line)
	{
		map[x] = split_and_malloc_line(env, y, line);
		if (!map[x])
			return (free_invalid_map(fd, map), close(fd), NULL);
		line = get_next_line(fd);
		y++;
		x++;
	}
	map[x] = NULL;
	close(fd);
	return (map);
}
