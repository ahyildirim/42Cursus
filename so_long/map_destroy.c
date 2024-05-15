/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:35:34 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:35 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct(t_map *data)
{
	data->i = -1;
	while (++data->i < data->map_height)
		free(data->map[data->i]);
	free(data->map);
	data->i = -1;
	while (++data->i < data->map_height)
		free(data->cpymap[data->i]);
	free(data->cpymap);
	free(data->map_location);
	free(data->array_map);
	free(data->mlx);
	free(data);
}

void	free_mlx(t_map *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->wall);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->floor);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->exit);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->collectables);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->player);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->enemy);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	free(data->mlx->mlx_ptr);
	free_struct(data);
}

int	close_window(t_map *data)
{
	free_mlx(data);
	ft_printf("Window closed\n");
	exit(0);
}

void	game_won(t_map *data)
{
	free_mlx(data);
	ft_printf("\n\t\t\t\tYOU HAVE WON THE GAME\t\t\t\t\n");
	exit(0);
}

void	game_over(t_map *data)
{
	free_mlx(data);
	ft_printf("\n\t\t\t\tYOU HAVE LOST THE GAME\t\t\t\t\n");
	exit(0);
}
