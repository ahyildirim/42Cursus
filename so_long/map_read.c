/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/08 21:35:38 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:39 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_location(t_map *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_xloc = j;
				data->p_yloc = i;
			}
			if (data->map[i][j] == 'E')
			{
				data->e_xloc = j;
				data->e_yloc = i;
			}
		}
	}
}

void	find_enemy_location(t_map *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'B')
			{
				data->en_xloc = j;
				data->en_yloc = i;
			}
		}
	}
}

int	height_of_map(t_map *data)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		free(line);
		line = get_next_line(data->fd);
		height++;
	}
	close(data->fd);
	data->fd = open(data->map_location, O_RDWR);
	free(line);
	return (height);
}

void	map_read(t_map *data)
{
	int	i;

	i = -1;
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	data->cpymap = malloc(sizeof(char *) * (data->map_height + 1));
	if (data->map == NULL || data->cpymap == NULL)
		map_error("Memory error", data);
	while (++i < data->map_height)
		data->map[i] = get_next_line(data->fd);
	data->map[i] = NULL;
	i = -1;
	close(data->fd);
	data->fd = open(data->map_location, O_RDWR);
	while (++i < data->map_height)
		data->cpymap[i] = get_next_line(data->fd);
	data->cpymap[i] = NULL;
	close(data->fd);
	data->fd = open(data->map_location, O_RDWR);
	find_location(data);
	find_enemy_location(data);
}

void	matrix_to_array(t_map *data)
{
	int	k;

	k = 0;
	data->i = -1;
	data->array_map = malloc(sizeof(char) * (data->map_height * data->map_width)
			+ 1);
	if (data->array_map == NULL)
		array_map_error("Memory error", data);
	ft_memset(data->array_map, 0, sizeof(char) * (data->map_height
			* data->map_width) + 1);
	while (++data->i < data->map_height)
	{
		data->j = -1;
		while (data->map[data->i][++data->j])
			data->array_map[k++] = data->map[data->i][data->j];
	}
	if (data->map_height > 22 || data->map_width > 41)
		array_map_error("Map is too long", data);
}
