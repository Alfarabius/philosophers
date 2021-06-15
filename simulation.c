#include "philosophers.h"

/*
Taken fork if both avilable
Each time a philosopher has finished eating, he will drop his forks and start sleeping.
When a philosopher is done sleeping, he will start thinking.
The simulation stops when a philosopher dies.
*/

void	start_simulation(t_philo **philo, t_opts *opts, t_sim *sim)
{
	uint64_t		number;
	struct timeval	time;

	number = 0;
	while (number < opts->philo_amount)
	{
		pthread_create(&philo[number]->life, NULL, start, (void *)philo[number]);
		number++;
	}
	gettimeofday(&time, NULL);
	*sim->start_time =	(time.tv_usec / 1000) + (time.tv_sec * 1000);
	*sim->is_start = TRUE;
	pthread_mutex_lock(sim->someone_dead);
	write (1, "del simulation\n", 16);
}
