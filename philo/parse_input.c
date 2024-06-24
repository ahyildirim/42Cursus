#include "philosophers.h"

static int check_args(t_table *table, int ac)
{
	if(ac == 5)
	{
		if(table->number_of_philo < 1 || table->time_to_die < 0 || table->time_to_eat < 0 || table->time_to_sleep < 0)
			return (1);
	}
	if(ac == 6)
		if(table->max_meals < 0)
			return (1);
	return (0);
}

static int mutex_init(t_table *table)
{
	int	i;

	i = -1;
	table->philo = malloc(sizeof(t_philo) * table->number_of_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->number_of_philo);
	while(++i < table->number_of_philo)
		if(pthread_mutex_init(table->forks, NULL))
			return (1);
	if(pthread_mutex_init(&table->writing, NULL))
		return (1);
	if(pthread_mutex_init(&table->die_check, NULL))
		return (1);
	return (0);
}

static int philo_init(t_table *table)
{
	int	i;

	i = -1;
	while(++i < table->number_of_philo)
	{
		table->philo[i].id = i;
		table->philo[i].lhand = i;
		table->philo[i].rhand = (i + 1) % table->number_of_philo;
		table->philo[i].last_eat_time = 0;
		table->philo[i].meals = 0;
		table->philo[i].table = table;
	}
	return (0);
}

int parse_input(t_table *table, char **av, int ac)
{
	table->number_of_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->is_died = 1;
	table->is_full = 1;
	if(ac == 6)
		table->max_meals = ft_atol(av[5]);
	else
		table->max_meals = -1;
	if(check_args(table, ac))
		ft_error_msg("Wrong input values, please check your inputs.");
	if(mutex_init(table))
		ft_error_msg("An error occured during mutex initialization, try again.");
	if(philo_init(table))
		ft_error_msg("An error occured during philo initialization, try again.");
	return (0);
}