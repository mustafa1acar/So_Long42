/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:26:13 by macar             #+#    #+#             */
/*   Updated: 2022/02/20 11:32:12 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_initialize(t_slong *map)
{
	map->collect_count = 0;
	map->column = 0;
	map->exit_count = 0;
	map->row = 0;
	map->starting_count = 0;
	map->height = 0;
	map->width = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->is_exit = 0;
}

int	ft_strlen2(char **s)
{
	int	i;
	int	ref;

	i = 0;
	ref = ft_strlen(s[0]);
	while (s[i])
	{
		if (ft_strlen(s[i++]) != ref)
		{
			free_all_map(s);
			ft_printf("Error\n Hataaa");
			exit(4);
		}
	}
	return (ref);
}

char	**map_maker3(char *str)
{
	char	**returned;

	returned = ft_split(str, '\n');
	if (returned[0] == 0)
	{
		free_all_map(returned);
		ft_printf("Error\n Hataaaa");
		exit(8);
	}
	return (returned);
}

char	**map_maker(char *str, t_slong *m)
{
	char	*temp;
	char	**returned;
	char	*map;
	char	*hold;
	int		fd;

	fd = map_maker2(str);
	hold = NULL;
	map = ft_strdup("");
	temp = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		hold = map;
		map = ft_strjoin(hold, temp);
		m->row++;
		free(hold);
		free(temp);
	}
	returned = map_maker3(map);
	free(map);
	m->column = ft_strlen2(returned);
	return (returned);
}

void	put_stri(t_slong *map)
{
	char	*p;

	p = ft_itoa(map->collect_count);
	mlx_string_put(map->mlx, map->win, 30, 100, 150, "Kalan Yuzuk");
	mlx_string_put(map->mlx, map->win, 115, 100, 150, p);
	if (map->collect_count == 0)
	{
		mlx_string_put(map->mlx, map->win, 30, 150, 199, "Toplanacak Yuzuk");
		mlx_string_put(map->mlx, map->win, 30, 160, 199, " Kalmadi!!");
		mlx_string_put(map->mlx, map->win, 30, 170, 232, "Prensese Git!");
	}
	if (map->collect_count == 0 && map->is_exit != 0)
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_string_put(map->mlx, map->win, 140, 200, 160, "Oyun Bitti!! ");
		mlx_string_put(map->mlx, map->win, 140, 220, 170, "Cikmak icin:> ");
		mlx_string_put(map->mlx, map->win, 140, 230, 180, "ESC ya da Q");
		mlx_string_put(map->mlx, map->win, 140, 240, 190, "Tusuna Basiniz! :D");
	}
	put_str2(map);
	free(p);
}
