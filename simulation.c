#include "philosophers.h"

/*
Taken fork if both avilable
Each time a philosopher has finished eating, he will drop his forks and start sleeping.
When a philosopher is done sleeping, he will start thinking.
The simulation stops when a philosopher dies.
*/

void	start_simulation(t_philo **philo, t_opts *opts, t_sim *sim)
{
	uint8_t			all_philosophers_are_alive;
	uint64_t		number;
	struct timeval	time;

	number = 0;
	all_philosophers_are_alive = TRUE;
	gettimeofday(&time, NULL);
	*sim->start_time =	(time.tv_usec / 1000) + (time.tv_sec * 1000);
	while (number < opts->philo_amount)
	{
		pthread_create(&philo[number]->life, NULL, start, (void *)philo[number]);
		usleep(1);
		number++;
	}
	sim->is_start = TRUE;
	while(all_philosophers_are_alive)
	{
		if(sim->someone_dead)
			all_philosophers_are_alive = FALSE;
	}
}
