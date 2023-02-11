/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:24:47 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 10:05:33 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, u_int32_t color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(u_int32_t *)dst = color;
}

static void	invers_point(t_point *p1, t_point *p2)
{
	t_point	tmp;

	if (p2->y < p1->y)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}

static void	my_mlx_put_line(t_data *data, t_point p1, t_point p2)
{
	float	steps;
	float	d_x;
	float	d_y;
	float	x_inc;
	float	y_inc;

	invers_point(&p1, &p2);
	d_x = p2.x - p1.x;
	d_y = p2.y - p1.y;
	if (d_x > d_y)
		steps = d_x;
	else
		steps = d_y;
	x_inc = d_x / steps;
	y_inc = d_y / steps;
	while (steps >= 0)
	{
		if (p1.x < 1920 && p1.x > 0 && p1.y < 1080 && p1.y > 0)
			my_mlx_pixel_put(data, p1.x, p1.y, p1.color);
		p1.x += x_inc;
		p1.y += y_inc;
		steps--;
	}
}

void	draw_all_lines(t_data img, t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (x < env->column - 1)
		{
			if (x < env->column - 2)
				my_mlx_put_line(&img, env->map[y][x], env->map[y][x + 1]);
			if (y < env->row - 2)
				my_mlx_put_line(&img, env->map[y][x], env->map[y + 1][x]);
			x++;
		}
		y++;
	}
}
