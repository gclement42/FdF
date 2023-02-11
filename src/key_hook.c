/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:02:41 by gclement          #+#    #+#             */
/*   Updated: 2023/02/10 13:56:38 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		free_and_exit(env);
	if (keycode == 65451 || keycode == 65453)
		key_hook_move(keycode, env);
	if (keycode >= 65361 || 65364 >= keycode)
		key_hook_move(keycode, env);
	return (0);
}

int	key_hook_move(int keycode, t_env *env)
{	
	if (keycode == 65451 || keycode == 65453)
		zoom(keycode, env);
	if (keycode >= 65361 || 65364 >= keycode)
		move(keycode, env);
	if (env->mlx && env->img.img && env->win)
		env->img = create_img(env);
	return (0);
}
