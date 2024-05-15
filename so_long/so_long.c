/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:35:43 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:45 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(t_map *data)
{
	char	*moves;
	char	*steps;
	char	*tmp;

	moves = ft_itoa(data->moves - 1);
	steps = ft_strdup("Steps: ");
	tmp = ft_strjoin(steps, moves);
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win_ptr, 15, 30, 0xFFFFFF,
		tmp);
	free(moves);
	free(steps);
	free(tmp);
}

int	main(int ac, char **av)
{
	t_map	*data;

	data = malloc(sizeof(t_map));
	if (data == NULL)
		error_msg("Memory error", data);
	if (ac != 2)
		error_msg("Please insert a map", data);
	data->player = 0;
	data->exit = 0;
	data->coins = 0;
	data->moves = 1;
	data->map_location = map_name(av[1], data);
	data->map_height = height_of_map(data);
	map_read(data);
	wall_control(data);
	matrix_to_array(data);
	check_chars(data);
	recursive_map(data, data->p_xloc, data->p_yloc);
	check_reachable(data);
	create_window(data);
	display_steps(data);
	mlx_key_hook(data->mlx->win_ptr, input_handler, data);
	mlx_hook(data->mlx->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx->mlx_ptr);
	return (0);
}
