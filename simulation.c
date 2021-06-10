#include "philosophers.h"

/*
Taken fork if both avilable
Each time a philosopher has finished eating, he will drop his forks and start sleeping.
When a philosopher is done sleeping, he will start thinking.
The simulation stops when a philosopher dies.
*/

void	start_simulation(t_philo **philo, t_opts *opts)
{
	uint8_t		all_philosophers_are_alive;
	uint64_t	number;

	number = 0;
	all_philosophers_are_alive = TRUE;
	while (number < opts->philo_amount)
	{
		pthread_create(&philo[number]->life, NULL, start, (void *)philo[number]);
		number++;
	}
	while (all_philosophers_are_alive)
	{
		number = 0;
		while (number < opts->philo_amount)
		{
			if (philo[number]->is_alive == FALSE)
				all_philosophers_are_alive = FALSE;
			number++;
		}
	}
}
