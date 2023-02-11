/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:52 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 11:33:58 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	zoom(int keycode, t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (x < env->column)
		{
			if (keycode == 65451)
			{
				env->map[y][x].x *= 1.10;
				env->map[y][x].y *= 1.10;
			}
			else
			{	
				env->map[y][x].x *= 0.90;
				env->map[y][x].y *= 0.90;
			}
			x++;
		}
		y++;
	}
}

void	move(int keycode, t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (x < env->column)
		{
			if (keycode == 65364)
				env->map[y][x].y += 50;
			else if (keycode == 65362)
				env->map[y][x].y -= 50;
			else if (keycode == 65363)
				env->map[y][x].x += 50;
			else if (keycode == 65361)
				env->map[y][x].x -= 50;
			x++;
		}	
		y++;
	}
}
