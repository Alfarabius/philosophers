#include "philosophers.h"

static void	*dead_checker(void *simul)
{
	uint64_t	amount;
	t_sim		*sim;
	t_philo		*philo;
	time_t		pause;

	sim = (t_sim *)simul;
	while (TRUE)
	{
		usleep(100);
		amount = sim->opts->philo_amount;
		while(amount)
		{
			amount--;
			philo = sim->philo[amount];
			pause = get_timestamp(*philo) - philo->last_meal_time;
			if (pause >= philo->opts->time_to_die)
			{
				philo->fdie((void *)philo);
				printf("last_meal = %ld", philo->last_meal_time);
				pthread_mutex_lock(sim->simulation);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	start_simulation(t_philo **philo, t_opts *opts, t_sim *sim)
{
	uint64_t		number;
	struct timeval	time;
	pthread_t		dead_waiter;

	number = 0;
	gettimeofday(&time, NULL);
	*sim->start_time =	(time.tv_usec / 1000) + (time.tv_sec * 1000);
	while (number < opts->philo_amount)
	{
		pthread_create(&philo[number]->life, NULL, start, (void *)philo[number]);
		number++;
	}
	// dead_checker((void *)sim);
	pthread_create(&dead_waiter, NULL, dead_checker, (void *)sim);
	pthread_mutex_lock(sim->someone_dead);
	pthread_detach(dead_waiter);
}
