#include "philosophers.h"

static void	*dead_checker(void *simul)
{
	int			amount;
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
				printf("last_meal = %ld\n", philo->last_meal_time);
				pthread_mutex_lock(sim->simulation);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	start_simulation(t_philo **philo, t_opts *opts, t_sim *sim)
{
	int				number;

	number = 0;
	while (number < opts->philo_amount)
	{
		pthread_create(&philo[number]->life, NULL, start, (void *)philo[number]);
		number++;
	}
	*sim->start_time =	get_time();
	pthread_mutex_unlock(sim->is_start);
	dead_checker((void *)sim);
}
