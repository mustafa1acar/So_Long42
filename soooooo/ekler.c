/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ekler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:23:40 by macar             #+#    #+#             */
/*   Updated: 2022/02/20 10:56:54 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_image_initializer2(t_slong *map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
		{
			if (map->map[height][width] == '1')
				put_image(map, 1, width, height);
			if (map->map[height][width] == 'C')
				put_image(map, 2, width, height);
			if (map->map[height][width] == 'P')
				put_man_image(map, map->p_x, map->p_y);
			if (map->map[height][width] == 'E')
				put_image(map, 4, width, height);
			width++;
		}
		height++;
	}
	put_stri(map);
}

int	map_maker2(char *str)
{
	int	fd;

	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n dosya okunmad");
		exit(2);
	}
	return (fd);
}

int	wall_checker2(int i, int rowson, int columnson, char **map)
{
	while (i <= rowson)
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i <= rowson)
	{
		if (map[i][columnson] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	general_control(char **map, int i, int y)
{
	if (map[i][y] != 'E' && map[i][y] != 'P'
		&& map[i][y] != 'C'
		&& map[i][y] != '1' && map[i][y] != '0')
	{
		return (0);
	}
	return (1);
}

void	put_str2(t_slong *map)
{
	char	*p2;

	p2 = ft_itoa(map->move_count);
	if (map->is_exit == 0)
	{
		mlx_string_put(map->mlx, map->win, 20, 40, 150, "Hareket sayisi: ");
		mlx_string_put(map->mlx, map->win, 150, 40, 150, p2);
		ft_printf("Hareket sayisi: %s\r", p2);
	}
	free(p2);
}
