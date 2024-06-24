#include "philosophers.h"

long long	get_current_time()
{
	struct timeval t_timeval;

	gettimeofday(&t_timeval, NULL);
	return ((t_timeval.tv_sec * 1000) + (t_timeval.tv_usec / 1000));
}

long long	time_diff(long long last_time, long long current_time)
{
	return (current_time - last_time);
}

void	ft_wait(long long wait_time, t_table *table)
{
	long long	time;

	time = get_current_time();
	while(table->is_died)
	{
		if(wait_time <= time_diff(time, get_current_time()))
			break;
		if(table->number_of_philo < 50)
			usleep(50);
	}
}
