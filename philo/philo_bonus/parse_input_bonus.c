/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:29:41 by ahyildir          #+#    #+#             */
/*   Updated: 2024/06/30 17:29:42 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_args(t_table *table, int ac)
{
	if (ac == 5)
	{
		if (table->number_of_philos < 1 || table->time_to_die < 0
			|| table->time_to_eat < 0 || table->time_to_sleep < 0)
			return (1);
	}
	if (ac == 6)
		if (table->max_meals < 0)
			return (1);
	return (0);
}

static int	semaphore_init(t_table *table)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_writing");
	sem_unlink("/sem_die_check");
	sem_unlink("/sem_meal_check");
	table->forks = sem_open("/sem_forks", O_CREAT, 0644,
			table->number_of_philos);
	table->writing = sem_open("/sem_writing", O_CREAT, 0644, 1);
	table->die_check = sem_open("/sem_die_check", O_CREAT, 0644, 1);
	table->die_check = sem_open("/sem_meal_check", O_CREAT, 0644, 1);
	if (table->forks == SEM_FAILED || table->die_check == SEM_FAILED
		|| table->writing == SEM_FAILED || table->meal_check == SEM_FAILED)
		return (1);
	return (0);
}

static int	philo_init(t_table *table)
{
	int	i;

	i = -1;
	table->philo = malloc(sizeof(t_philo) * table->number_of_philos);
	if (!table->philo)
		return (1);
	while (++i < table->number_of_philos)
	{
		table->philo[i].id = i;
		table->philo[i].meal_counter = 0;
		table->philo[i].last_eat_time = 0;
		table->philo[i].table = table;
	}
	return (0);
}

int	parse_input(t_table *table, char **av, int ac)
{
	table->number_of_philos = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->is_died = 0;
	if (ac == 6)
		table->max_meals = ft_atol(av[5]);
	else
		table->max_meals = -1;
	if (check_args(table, ac))
		ft_error("Wrong input values, please check your inputs.");
	if (semaphore_init(table))
		ft_error("An error occurred while semaphore initialization.");
	if (philo_init(table))
		ft_error("An error occured during philo initialization.");
	return (0);
}
