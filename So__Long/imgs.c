/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:41:12 by macar             #+#    #+#             */
/*   Updated: 2022/02/15 17:46:09 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_slong *map, int a, int width, int height)
{
	if (a == 3)
		mlx_put_image_to_window(map->mlx, (map)->win, map->player_standard,
			(width * 75), (height * 75));
	if (a == 1)
		mlx_put_image_to_window(map->mlx, (map)->win, map->wall,
			(width * 75), (height * 75));
	if (a == 2)
		mlx_put_image_to_window(map->mlx, (map)->win, map->collect,
			(width * 75), (height * 75));
	if (a == 4)
		mlx_put_image_to_window(map->mlx, (map)->win, map->exit,
			(width * 75), (height * 75));
}

void	image_creator(t_slong *map)
{
	int	w;
	int	h;

	map->wall = mlx_xpm_file_to_image(map->mlx, IMG_WALL, &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, IMG_EXIT, &w, &h);
	map->player_standard = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER, &w, &h);
	map->collect = mlx_xpm_file_to_image(map->mlx, IMG_COLLECT, &w, &h);
}

void	put_man_image(t_slong *map, int w, int h)
{
	if (map->player_direction == 'w')
		mlx_put_image_to_window(map->mlx, map->win,
			map->player_w, w * 75, h * 75);
	if (map->player_direction == 's')
		mlx_put_image_to_window(map->mlx, map->win,
			map->player_s, w * 75, h * 75);
	if (map->player_direction == 'a')
		mlx_put_image_to_window(map->mlx, map->win,
			map->player_a, w * 75, h * 75);
	if (map->player_direction == 'd')
		mlx_put_image_to_window(map->mlx, map->win,
			map->player_d, w * 75, h * 75);
}

void	man_image_creator(t_slong *param)
{
	int	w;
	int	h;

	param->player_w = mlx_xpm_file_to_image(param->mlx, PLAYER_W, &w, &h);
	param->player_a = mlx_xpm_file_to_image(param->mlx, PLAYER_A, &w, &h);
	param->player_s = mlx_xpm_file_to_image(param->mlx, PLAYER_S, &w, &h);
	param->player_d = mlx_xpm_file_to_image(param->mlx, PLAYER_D, &w, &h);
}

void	image_initializer(t_slong *map, char **nowmap, int height, int width)
{
	image_creator(map);
	while (nowmap[height])
	{
		width = 0;
		while (nowmap[height][width])
		{
			if (nowmap[height][width] == '1')
				put_image(map, 1, width, height);
			if (nowmap[height][width] == 'C')
				put_image(map, 2, width, height);
			if (nowmap[height][width] == 'P')
			{
				put_image(map, 3, width, height);
				map->p_x = width;
				map->p_y = height;
			}	
			if (nowmap[height][width] == 'E')
				put_image(map, 4, width, height);
			width++;
		}
		height++;
	}
}
