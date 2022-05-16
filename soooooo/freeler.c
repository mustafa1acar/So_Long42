/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:25:10 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 13:02:50 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	just_destroyer(t_slong *param)
{
	free_all_map(param->map);
	mlx_destroy_image(param->mlx, param->wall);
	mlx_destroy_image(param->mlx, param->player_standard);
	mlx_destroy_image(param->mlx, param->exit);
	mlx_destroy_image(param->mlx, param->collect);
	mlx_destroy_image(param->mlx, param->player_w);
	mlx_destroy_image(param->mlx, param->player_a);
	mlx_destroy_image(param->mlx, param->player_s);
	mlx_destroy_image(param->mlx, param->player_d);
	mlx_destroy_window(param->mlx, param->win);
}

void	free_all_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	key_press2(int keycode, t_slong *param)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		mlx_clear_window(param->mlx, param->win);
		if (yer_degistirme(param, param->p_x - 1, param->p_y, 'a'))
			param->map[param->p_y][param->p_x + 1] = '0';
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		mlx_clear_window(param->mlx, param->win);
		if (yer_degistirme(param, param->p_x + 1, param->p_y, 'd'))
			param->map[param->p_y][param->p_x - 1] = '0';
	}
}

int	closed_window(t_slong *param)
{
	mlx_clear_window(param->mlx, param->win);
	just_destroyer(param);
	exit(2);
}

void	ft_error(void)
{
	ft_printf("Error\nharitanizda hata var");
	exit(1);
}
