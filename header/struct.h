/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:26:47 by gclement          #+#    #+#             */
/*   Updated: 2023/01/17 08:52:48 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	int			z;
	float		x;
	float		y;
	u_int32_t	color;
}	t_point;

typedef struct s_env
{
	t_point	**map;
	int		column;
	int		row;
	float	max_y;
	float	max_x;
	void	*mlx;
	void	*win;
	t_data	img;
}	t_env;

#endif