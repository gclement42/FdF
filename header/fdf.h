/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:56:48 by gclement          #+#    #+#             */
/*   Updated: 2023/02/11 11:08:47 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <../minilibx_linux/mlx.h>
# include "../libft/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>

int		key_hook(int keycode, t_env *env);
int		key_hook_move(int keycode, t_env *env);

void	my_mlx_pixel_put(t_data *data, int x, int y, u_int32_t color);

void	draw_all_lines(t_data img,	t_env *env);

t_data	create_img(t_env *env);
void	init_mlx_create_win(t_env *env);

void	zoom(int keycode, t_env *env);
void	move(int keycode, t_env *env);
void	center_map(t_env *env);

t_point	**parsing_map(char *map, t_env *env);

t_point	parsing_rotate(t_point point, int cord_y, int cord_x, t_env *env);
void	calc_max(t_env *env, int l);
int		count_row(char *map_txt);

void	*free_2d_array(t_point **map);
void	*free_2d_array_char(char **ptr);
int		free_and_exit(t_env *env);
void	free_invalid_map(int fd, t_point **map);

#endif