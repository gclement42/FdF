/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:02:40 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 11:35:51 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	main(int argc, char *argv[])
{
	t_env		env;

	if (argc != 2)
	{
		ft_printf("too many arguments\n");
		exit (0);
	}
	env.max_x = 0;
	env.max_y = 0;
	env.map = parsing_map(argv[1], &env);
	if (!env.map)
		exit(EXIT_FAILURE);
	init_mlx_create_win(&env);
	mlx_hook(env.win, 2, 1L << 0, key_hook, &env);
	mlx_hook(env.win, 17, 1L << 0, free_and_exit, &env);
	mlx_loop(env.mlx);
	exit(0);
}
