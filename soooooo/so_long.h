/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:00:54 by macar             #+#    #+#             */
/*   Updated: 2022/02/20 10:48:08 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "getnextline/get_next_line.h"

typedef struct s_slong
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		p_x;
	int		p_y;
	int		column;
	int		row;
	int		exit_count;
	int		starting_count;
	int		collect_count;
	void	*wall;
	void	*exit;
	void	*space;
	void	*player_standard;
	void	*player_a;
	void	*player_s;
	void	*player_w;
	void	*player_d;
	void	*collect;
	int		height;
	int		width;
	char	player_direction;
	int		move_count;
	int		is_exit;

}	t_slong;

int		wall_checker(t_slong *m);
int		extension_checker(char *str);
int		other_checks(t_slong *m);
int		is_rectangular(t_slong *map);
int		map_checker(t_slong *map, char *str);
void	put_image(t_slong *map, int a, int width, int height);
void	image_creator(t_slong *map);
void	put_man_image(t_slong *map, int w, int h);
void	man_image_creator(t_slong *param);
void	image_initializer(t_slong *map, char **m, int height, int width);
void	new_image_initializer2(t_slong *map);
void	put_stri(t_slong *map);
char	**map_maker(char *str, t_slong *m);
int		ft_strlen2(char **s);
void	map_initialize(t_slong *map);
void	free_all_map(char **map);
void	free_pointer(void **s);
void	just_destroyer(t_slong *param);
void	key_press2(int keycode, t_slong *param);
void	new_image_initializer2(t_slong *map);
char	*ft_itoa(int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		map_maker2(char *str);
int		wall_checker2(int i, int rowson, int columnson, char **map);
int		general_control(char **map, int i, int y);
int		yer_degistirme(t_slong *ma, int x, int y, char yon);
void	put_str2(t_slong *map);
int		closed_window(t_slong *param);
void	ft_error(void);

# define WALL_IMAGE void *
# define EXIT_IMAGE void *
# define PLAYER_IMAGE void *
# define COLLECT_IMAGE void *
# define IMG_SPACE "textures/map/bosluk.xpm"
# define IMG_WALL "textures/map/xpmlazim.xpm"
# define IMG_COLLECT "karakter/collect/collect.xpm"
# define IMG_EXIT "karakter/exit/exit.xpm"
# define IMG_PLAYER "karakter/adam/standard.xpm"
# define PLAYER_W "karakter/adam/p_W.xpm"
# define PLAYER_A "karakter/adam/p_A.xpm"
# define PLAYER_S "karakter/adam/p_S.xpm"
# define PLAYER_D "karakter/adam/p_D.xpm"

# define STANDARD_SIZE 75
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_SPACE 49

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

#endif