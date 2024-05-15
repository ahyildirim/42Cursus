/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/08 21:35:20 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:22 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_map *data)
{
	if (data->mlx->player == NULL || data->mlx->wall == NULL
		|| data->mlx->floor == NULL || data->mlx->collectables == NULL
		|| data->mlx->exit == NULL || data->mlx->enemy == NULL)
		error_msg("Missing image file!", data);
}

void	put_collectables(t_map *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->collectables, data->j * 64, data->i * 64);
}

void	put_enemy(t_map *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->enemy, data->j * 64, data->i * 64);
}

void	create_window(t_map *data)
{
	int	x;
	int	y;

	data->mlx = malloc(sizeof(t_mlx));
	if (data->mlx == NULL)
		error_msg("Memory error", data);
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, (data->map_width
				- 1) * 64, data->map_height * 64, "so_long");
	data->mlx->player = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			"images/player", &x, &y);
	data->mlx->wall = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "images/wall",
			&x, &y);
	data->mlx->floor = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "images/floor",
			&x, &y);
	data->mlx->collectables = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			"images/collectable", &x, &y);
	data->mlx->exit = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "images/exit",
			&x, &y);
	data->mlx->enemy = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "images/enemy",
			&x, &y);
	check_images(data);
	add_graphics(data);
}

void	add_graphics(t_map *data)
{
	data->i = -1;
	while (++data->i < data->map_height)
	{
		data->j = -1;
		while (data->map[data->i][++data->j])
		{
			if (data->map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
					data->mlx->wall, data->j * 64, data->i * 64);
			else if (data->map[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
					data->mlx->floor, data->j * 64, data->i * 64);
			else if (data->map[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
					data->mlx->player, data->j * 64, data->i * 64);
			else if (data->map[data->i][data->j] == 'C')
				put_collectables(data);
			else if (data->map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
					data->mlx->exit, data->j * 64, data->i * 64);
			else if (data->map[data->i][data->j] == 'B')
				put_enemy(data);
		}
	}
	display_steps(data);
}
