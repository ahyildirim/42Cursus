/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/08 21:35:28 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:29 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_name(char *av, t_map *data)
{
	int		len;
	char	*mapname;

	data->fd = open(av, O_RDONLY);
	if (data->fd == -1)
		error_msg("No such file or directory!", data);
	len = ft_strlen(av);
	mapname = ft_strdup(av);
	if (mapname[len - 1] != 'r' || mapname[len - 2] != 'e' || mapname[len
			- 3] != 'b' || mapname[len - 4] != '.')
	{
		free(mapname);
		error_msg("File extension must be .ber!", data);
	}
	return (mapname);
}

void	wall_control(t_map *data)
{
	data->i = -1;
	data->j = 0;
	data->map_width = ft_strlen(data->map[0]);
	while (++data->i < data->map_height)
		if (data->map_width != (int)ft_strlen(data->map[data->i]))
			map_error("Map is not rectangular", data);
	data->i = 0;
	while (data->j < data->map_width - 1)
	{
		if (data->map[data->i][data->j] == '1' && data->map[data->map_height
			- 1][data->j] == '1')
			data->j++;
		map_error("Map is not covered by walls", data);
	}
	while (data->i < data->map_height)
	{
		if (data->map[data->i][0] == '1' && data->map[data->i][data->map_width
			- 2] == '1')
			data->i++;
		map_error("Map is not covered by walls", data);
	}
}

void	check_missing_chars(t_map *data)
{
	if (data->player == 0 || data->coins == 0 || data->exit == 0)
		array_map_error("Missing character(s) in map", data);
}

void	check_chars(t_map *d)
{
	d->i = 0;
	while (d->i < d->map_width * d->map_height)
	{
		if (d->array_map[d->i] == '1' || d->array_map[d->i] == '0'
			|| d->array_map[d->i] == '\n')
			d->i++;
		else if ((d->array_map[d->i] == 'P' && d->player == 0)
			|| (d->array_map[d->i] == 'E' && d->exit == 0))
		{
			if (d->array_map[d->i] == 'P')
				d->player = 1;
			if (d->array_map[d->i++] == 'E')
				d->exit = 1;
		}
		else if (d->array_map[d->i] == 'C')
		{
			d->coins++;
			d->i++;
		}
		else if (d->array_map[d->i++] == 'B')
			d->enemy++;
		else
			array_map_error("Invalid character in the map", d);
	}
	check_missing_chars(d);
}
