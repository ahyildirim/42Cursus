#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define DEFAULT "\033[0m"

typedef struct s_philo
{
	int				id;
	int				lhand;
	int				rhand;
	int				meals;
	long long		last_eat_time;
	pthread_t		philos;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				number_of_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				max_meals;
	long long		first_eat_time;
	int				is_died;
	int				is_full;
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t writing;
	pthread_mutex_t die_check;
	t_philo			*philo;
}				t_table;

void		ft_error_msg(char *str);
int			parse_input(t_table *table, char **av, int ac);
long		ft_atol(const char *str);
int			start_simulation(t_table *table);
long long 	get_current_time();
void		philo_msg(char *str, t_table *table, int philo_id);
long long	time_diff(long long last_time, long long current_time);
void		ft_wait(long long wait_time, t_table *table);

#endif