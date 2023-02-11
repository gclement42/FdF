/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:50:47 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 10:55:14 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_point	parsing_rotate(t_point point, int cord_y, int cord_x, t_env *env)
{
	float	x;
	float	y;

	point.x = (float)(cord_x * 10) + 650;
	point.y = (float)(cord_y * 10);
	point.color = 0xffffff;
	x = point.x;
	y = point.y;
	point.z = point.z * 10;
	point.x = (x - y) / cos(1 * M_PI_4);
	point.y = ((x + y) * sin(1 * M_PI_4)) - point.z / sqrt(3);
	if (point.z != 0)
		point.y = (float) point.y - point.z;
	if (point.x > env->max_x)
		env->max_x = point.x;
	if (point.y > env->max_y)
		env->max_y = point.y;
	return (point);
}

int	count_row(char *map_txt)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(map_txt, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	i++;
	return (i);
}
