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
				printf("last_meal = %ld", philo->last_meal_time);
				pthread_mutex_lock(sim->simulation);
				return (NULL);
			}
		}
	}
	return (NULL);
}

static void	*priority_waiter(void *simul)
{
	int			amount;
	t_sim		*sim;
	t_philo		*philo;

	sim = (t_sim *)simul;
	pthread_mutex_lock(sim->is_start);
	pthread_mutex_unlock(sim->is_start);
	while (TRUE)
	{
		usleep(sim->opts->time_to_die / 2);
		amount = sim->opts->philo_amount;
		pthread_mutex_lock(sim->simulation);
		pthread_mutex_unlock(sim->simulation);
		while (amount)
		{
			amount--;
			philo = sim->philo[amount];
			if (philo->priority)
			{
				philo->can_eat = TRUE;
				if (amount == 0)
				{
					sim->philo[sim->opts->philo_amount - 1]->priority |= 1;
					sim->philo[1]->priority |= 1;
				}
				else if (amount == sim->opts->philo_amount - 1)
				{
					sim->philo[0]->priority |= 1;
					sim->philo[amount - 1]->priority |= 1;
				}
				else
				{
					sim->philo[amount - 1]->priority |= 1;
					sim->philo[amount + 1]->priority |= 1;
				}
			}
		}
	}
	return(NULL);
}

void	start_simulation(t_philo **philo, t_opts *opts, t_sim *sim)
{
	int				number;
	struct timeval	time;
	pthread_t		waiter;

	number = 0;
	while (number < opts->philo_amount)
	{
		pthread_create(&philo[number]->life, NULL, start, (void *)philo[number]);
		number++;
	}
	pthread_create(&waiter, NULL, priority_waiter, (void *)sim);
	gettimeofday(&time, NULL);
	*sim->start_time =	(time.tv_usec / 1000) + (time.tv_sec * 1000);
	pthread_mutex_unlock(sim->is_start);
	dead_checker((void *)sim);
}
