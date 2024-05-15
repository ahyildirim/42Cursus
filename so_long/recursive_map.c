/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:14:48 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/09 16:14:49 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	recursive_map(t_map *data, int x, int y)
{
	if (data->cpymap[y][x] == '1' || data->cpymap[y][x] == 'B')
		return ;
	data->cpymap[y][x] = '1';
	recursive_map(data, x, y + 1);
	recursive_map(data, x, y - 1);
	recursive_map(data, x + 1, y);
	recursive_map(data, x - 1, y);
}

void	check_reachable(t_map *data)
{
	data->i = 0;
	while (data->i < data->map_height)
	{
		data->j = 0;
		while (data->j < data->map_width - 1)
		{
			if (data->cpymap[data->i][data->j] == 'C'
				|| data->cpymap[data->i][data->j] == 'E')
				array_map_error("Unreachable items on map", data);
			data->j++;
		}
		data->i++;
	}
}
