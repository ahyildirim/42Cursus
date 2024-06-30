/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:29:48 by ahyildir          #+#    #+#             */
/*   Updated: 2024/06/30 17:29:49 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	eat_meal(t_philo *philo)
{
	sem_wait(philo->table->forks);
	philo_msg("has taken a fork", philo->table, philo->id);
	sem_wait(philo->table->forks);
	philo_msg("has taken a fork", philo->table, philo->id);
	sem_wait(philo->table->meal_check);
	philo_msg("is eating", philo->table, philo->id);
	philo->last_eat_time = get_current_time();
	sem_post(philo->table->meal_check);
	ft_wait(philo->table->time_to_eat, philo->table);
	philo->meal_counter++;
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
}

void	*die_check(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	while (1)
	{
		sem_wait(philo->table->meal_check);
		if (time_diff(philo->last_eat_time,
				get_current_time()) > philo->table->time_to_die)
		{
			philo_msg("is died", philo->table, philo->id);
			philo->table->is_died = 1;
			exit(EXIT_FAILURE);
		}
		sem_post(philo->table->meal_check);
		if (philo->table->is_died)
			break ;
		usleep(100);
		if (philo->table->max_meals != -1
			&& philo->meal_counter >= philo->table->max_meals)
			break ;
	}
	return (NULL);
}

void	philosopher_routine(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	philo->last_eat_time = get_current_time();
	pthread_create(&philo->die_thread, NULL, die_check, philo);
	if (philo->id % 2 == 1)
		usleep(15000);
	while (!philo->table->is_died)
	{
		if (philo->meal_counter >= philo->table->max_meals
			&& philo->table->max_meals != -1)
			break ;
		eat_meal(philo);
		philo_msg("is sleeping", philo->table, philo->id);
		ft_wait(philo->table->time_to_sleep, philo->table);
		philo_msg("is thinking", philo->table, philo->id);
	}
	pthread_join(philo->die_thread, NULL);
	if (philo->table->is_died)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static void	clear_all(t_table *table)
{
	int	i;
	int	status;

	i = -1;
	while (++i < table->number_of_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < table->number_of_philos)
				kill(table->philo[i].pid, SIGKILL);
		}
	}
	sem_close(table->forks);
	sem_close(table->meal_check);
	sem_close(table->writing);
	sem_close(table->die_check);
	sem_close(table->meal_check);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_writing");
	sem_unlink("/sem_die_check");
	sem_unlink("/sem_meal_check");
}

int	start_simulation(t_table *table)
{
	int	i;

	i = -1;
	table->sim_start_time = get_current_time();
	while (++i < table->number_of_philos)
	{
		table->philo[i].pid = fork();
		if (table->philo[i].pid < 0)
			return (1);
		if (table->philo[i].pid == 0)
			philosopher_routine(&table->philo[i]);
		usleep(100);
	}
	clear_all(table);
	return (0);
}
