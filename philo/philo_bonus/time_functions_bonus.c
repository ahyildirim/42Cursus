/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:30:02 by ahyildir          #+#    #+#             */
/*   Updated: 2024/06/30 17:30:02 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_current_time(void)
{
	struct timeval	t_timeval;

	gettimeofday(&t_timeval, NULL);
	return ((t_timeval.tv_sec * 1000) + (t_timeval.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_wait(long long wait_time, t_table *table)
{
	long long	time;

	time = get_current_time();
	while (!table->is_died)
	{
		if (wait_time <= time_diff(time, get_current_time()))
			break ;
		usleep(100);
	}
}
