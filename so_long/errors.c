/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:35:14 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:15 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *s, t_map *data)
{
	free(data);
	ft_printf("%s", s);
	exit(1);
}

void	map_error(char *s, t_map *data)
{
	data->i = -1;
	while (++data->i < data->map_height)
		free(data->map[data->i]);
	data->i = -1;
	while (++data->i < data->map_height)
		free(data->cpymap[data->i]);
	free(data->map);
	free(data->cpymap);
	free(data->map_location);
	free(data);
	ft_printf("%s", s);
	exit(1);
}

void	array_map_error(char *s, t_map *data)
{
	data->i = -1;
	while (++data->i < data->map_height)
		free(data->map[data->i]);
	data->i = -1;
	while (++data->i < data->map_height)
		free(data->cpymap[data->i]);
	free(data->map);
	free(data->cpymap);
	free(data->map_location);
	free(data->array_map);
	free(data);
	ft_printf("%s", s);
	exit(1);
}
