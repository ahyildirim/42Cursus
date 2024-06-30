/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:30:08 by ahyildir          #+#    #+#             */
/*   Updated: 2024/06/30 17:30:09 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(char *str)
{
	printf("%s%s%s", RED, str, DEFAULT);
	exit(EXIT_FAILURE);
}

static const char	*is_valid(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		ft_error("Please enter a positive value.");
	if (!(*str >= '0' && *str <= '9'))
		ft_error("Please enter numbers.");
	number = str;
	while (*str >= '0' && *str <= '9')
	{
		len++;
		str++;
	}
	if (len > 10)
		ft_error("Please enter between '0' and 'MAX_INT' values");
	return (number);
}

long	ft_atol(const char *str)
{
	int		i;
	long	num;

	num = 0;
	str = is_valid(str);
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i] - '0';
	if (num > INT_MAX)
		ft_error("Please enter between 'MIN_INT' and 'MAX_INT' values");
	return (num);
}

void	philo_msg(char *str, t_table *table, int philo_id)
{
	sem_wait(table->writing);
	if (table->is_died == 0)
	{
		printf("%s%lld%s", RED, time_diff(table->sim_start_time,
				get_current_time()), DEFAULT);
		printf("%s %d %s", GREEN, philo_id + 1, DEFAULT);
		printf("%s\n", str);
	}
	sem_post(table->writing);
}
