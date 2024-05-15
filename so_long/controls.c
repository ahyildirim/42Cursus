/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:35:09 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:35:10 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_map *d)
{
	if (d->map[d->p_yloc][d->p_xloc - 1] != '1')
	{
		ft_printf("Steps: %d\n", d->moves++);
		ft_printf("Coins Left: %d\n", d->coins);
		if (d->map[d->p_yloc][d->p_xloc - 1] == 'C')
			d->coins--;
		if (d->map[d->p_yloc][d->p_xloc - 1] == 'E' && d->coins == 0)
			game_won(d);
		if (d->map[d->p_yloc][d->p_xloc - 1] == 'B')
			game_over(d);
		if (d->p_yloc == d->e_yloc && d->p_xloc == d->e_xloc)
		{
			d->map[d->p_yloc][d->p_xloc] = 'E';
			add_graphics(d);
			d->p_xloc--;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
		else
		{
			d->map[d->p_yloc][d->p_xloc] = '0';
			d->p_xloc--;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
	}
}

void	move_right(t_map *d)
{
	if (d->map[d->p_yloc][d->p_xloc + 1] != '1')
	{
		ft_printf("Steps: %d\n", d->moves++);
		if (d->map[d->p_yloc][d->p_xloc + 1] == 'C')
			d->coins--;
		ft_printf("Coins Left: %d\n", d->coins);
		if (d->map[d->p_yloc][d->p_xloc + 1] == 'E' && d->coins == 0)
			game_won(d);
		if (d->map[d->p_yloc][d->p_xloc + 1] == 'B')
			game_over(d);
		if (d->p_yloc == d->e_yloc && d->p_xloc == d->e_xloc)
		{
			d->map[d->p_yloc][d->p_xloc] = 'E';
			add_graphics(d);
			d->p_xloc++;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
		else
		{
			d->map[d->p_yloc][d->p_xloc] = '0';
			d->p_xloc++;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
	}
}

void	move_down(t_map *d)
{
	if (d->map[d->p_yloc + 1][d->p_xloc] != '1')
	{
		ft_printf("Steps: %d\n", d->moves++);
		if (d->map[d->p_yloc + 1][d->p_xloc] == 'C')
			d->coins--;
		ft_printf("Coins Left: %d\n", d->coins);
		if (d->map[d->p_yloc + 1][d->p_xloc] == 'E' && d->coins == 0)
			game_won(d);
		if (d->map[d->p_yloc + 1][d->p_xloc] == 'B')
			game_over(d);
		if (d->p_yloc == d->e_yloc && d->p_xloc == d->e_xloc)
		{
			d->map[d->p_yloc][d->p_xloc] = 'E';
			add_graphics(d);
			d->p_yloc++;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
		else
		{
			d->map[d->p_yloc][d->p_xloc] = '0';
			d->p_yloc++;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
	}
}

void	move_up(t_map *d)
{
	if (d->map[d->p_yloc - 1][d->p_xloc] != '1')
	{
		ft_printf("Steps: %d\n", d->moves++);
		if (d->map[d->p_yloc - 1][d->p_xloc] == 'C')
			d->coins--;
		ft_printf("Coins Left: %d\n", d->coins);
		if (d->map[d->p_yloc - 1][d->p_xloc] == 'E' && d->coins == 0)
			game_won(d);
		if (d->map[d->p_yloc - 1][d->p_xloc] == 'B')
			game_over(d);
		if (d->p_yloc == d->e_yloc && d->p_xloc == d->e_xloc)
		{
			d->map[d->p_yloc][d->p_xloc] = 'E';
			add_graphics(d);
			d->p_yloc--;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
		else
		{
			d->map[d->p_yloc][d->p_xloc] = '0';
			d->p_yloc--;
			d->map[d->p_yloc][d->p_xloc] = 'P';
		}
	}
}

int	input_handler(int code, t_map *data)
{
	if (code == 53)
		close_window(data);
	if (code == 0 || code == 123)
		move_left(data);
	if (code == 2 || code == 124)
		move_right(data);
	if (code == 1 || code == 125)
		move_down(data);
	if (code == 13 || code == 126)
		move_up(data);
	add_graphics(data);
	return (0);
}
