/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/08 21:38:12 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:38:15 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectables;
	void	*enemy;
}			t_mlx;

typedef struct s_map
{
	char	*map_location;
	char	*array_map;
	char	**map;
	char	**cpymap;

	int		fd;
	int		i;
	int		j;
	int		map_width;
	int		map_height;
	int		p_xloc;
	int		p_yloc;
	int		e_xloc;
	int		e_yloc;
	int		en_xloc;
	int		en_yloc;
	int		enemy;
	int		player;
	int		coins;
	int		exit;
	int		moves;

	t_mlx	*mlx;
}			t_map;

void	error_msg(char *s, t_map *data);
void	map_error(char *s, t_map *data);
void	array_map_error(char *s, t_map *data);
void	map_read(t_map *data);
void	wall_control(t_map *data);
void	matrix_to_array(t_map *data);
void	check_chars(t_map *d);
void	recursive_map(t_map *data, int x, int y);
void	check_reachable(t_map *data);
void	create_window(t_map *data);
void	add_graphics(t_map *data);
void	free_mlx(t_map *data);
void	game_won(t_map *data);
void	display_steps(t_map *data);
void	game_over(t_map *data);
char	*map_name(char *av, t_map *data);
int		height_of_map(t_map *data);
int		close_window(t_map *data);
int		input_handler(int code, t_map *data);

#endif
