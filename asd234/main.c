/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:12:29 by macar             #+#    #+#             */
/*   Updated: 2022/02/20 11:08:27 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	yer_degistirme2(t_slong *ma, int x, int y, char yon)
{
	if (ma->map[y][x] == 'E' && ma->collect_count == 0)
	{
		ma->map[y][x] = 'P';
		ma->player_direction = yon;
		ma->p_x = x;
		ma->p_y = y;
		ma->is_exit++;
		ma->move_count++;
		put_stri(ma);
		return (1);
	}
	return (0);
}

int	yer_degistirme(t_slong *ma, int x, int y, char yon)
{
	if (ma->map[y][x] == '0')
	{
		ma->map[y][x] = 'P';
		ma->player_direction = yon;
		ma->p_x = x;
		ma->p_y = y;
		ma->move_count++;
		return (1);
	}
	if (ma->map[y][x] == 'C')
	{
		ma->map[y][x] = 'P';
		ma->player_direction = yon;
		ma->p_x = x;
		ma->p_y = y;
		ma->collect_count--;
		ma->move_count++;
		return (1);
	}
	if (ma->map[y][x] == 'E' && ma->collect_count == 0)
	{
		if (yer_degistirme2(ma, x, y, yon))
			return (1);
	}
	return (0);
}

int	initialize_game(t_slong *m)
{	
	m->mlx = mlx_init();
	if (!(m->mlx))
		return (0);
	m->win = mlx_new_window(m->mlx, m->column * 75, m->row * 75, "So Long");
	if (!(m->win))
		return (0);
	image_initializer(m, m->map, m->height, m->width);
	return (1);
}

int	key_pressed(int keycode, t_slong *param)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_clear_window(param->mlx, param->win);
		just_destroyer(param);
		exit(2);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		mlx_clear_window(param->mlx, param->win);
		if (yer_degistirme(param, param->p_x, param->p_y - 1, 'w'))
			param->map[param->p_y + 1][param->p_x] = '0';
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		mlx_clear_window(param->mlx, param->win);
		if (yer_degistirme(param, param->p_x, param->p_y + 1, 's'))
			param->map[param->p_y - 1][param->p_x] = '0';
	}
	key_press2(keycode, param);
	new_image_initializer2(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_slong	game;

	if (argc == 2)
	{
		map_initialize(&game);
		game.map = map_maker(argv[1], &game);
		if (map_checker(&game, argv[1]))
		{
			if (!initialize_game(&game))
				return (0);
			man_image_creator(&game);
			mlx_hook(game.win, 2, 1L << 0, key_pressed, &game);
			mlx_hook(game.win, 17, 1L << 2, closed_window, &game);
			mlx_loop(game.mlx);
		}
		else
			ft_error();
	}
	else
		ft_error();
	pause();
	return (0);
}
