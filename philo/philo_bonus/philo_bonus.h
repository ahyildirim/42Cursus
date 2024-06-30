/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:29:25 by ahyildir          #+#    #+#             */
/*   Updated: 2024/06/30 17:29:26 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	long long		last_eat_time;
	pid_t			pid;
	pthread_t		die_thread;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				is_died;
	long long		sim_start_time;
	sem_t			*forks;
	sem_t			*writing;
	sem_t			*die_check;
	sem_t			*meal_check;
	t_philo			*philo;
}					t_table;

void				ft_error(char *str);
void				ft_wait(long long wait_time, t_table *table);
void				philo_msg(char *str, t_table *table, int philo_id);

int					parse_input(t_table *table, char **av, int ac);
int					start_simulation(t_table *table);

long				ft_atol(const char *str);
long long			get_current_time(void);
long long			time_diff(long long past, long long present);

#endif
