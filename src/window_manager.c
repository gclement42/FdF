/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:32 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 11:00:49 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_data	create_img(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, 1920, 1080);
	env->img.addr = mlx_get_data_addr(env->img.img, \
	&env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	draw_all_lines(env->img, env);
	mlx_put_image_to_window(env->mlx, env->win, \
		env->img.img, 0, 0);
	return (env->img);
}

void	init_mlx_create_win(t_env *env)
{
	t_data		img;

	env->mlx = mlx_init();
	if (!env->mlx)
		free_and_exit(env);
	env->win = mlx_new_window(env->mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(env->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (!env->map || !img.img || !img.addr || !env->win)
		free_and_exit(env);
	env->img = img;
	draw_all_lines(env->img, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}
