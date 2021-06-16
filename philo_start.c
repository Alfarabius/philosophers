#include "philosophers.h"

static void	check_simulation(t_philo *philo)
{
	pthread_mutex_lock(philo->simulation);
	pthread_mutex_unlock(philo->simulation);
}

void	*start(void *self)
{
	t_philo			*philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	philo = (t_philo *)self;
	if (philo->left_fork_number > philo->number)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	philo->last_meal_time = get_timestamp(*philo);
	while (philo->is_alive)
	{
		check_simulation(philo);
		philo->ftake_a_fork(philo, first_fork);
		check_simulation(philo);
		philo->ftake_a_fork(philo, second_fork);
		philo->last_meal_time = get_timestamp(*philo);
		check_simulation(philo);
		philo->feat(philo, philo->opts->time_to_eat);
		check_simulation(philo);
		put_fork(second_fork);
		put_fork(first_fork);
		check_simulation(philo);
		philo->fsleep(philo, philo->opts->time_to_sleep);
		check_simulation(philo);
		philo->fthink(self);
	}
	return (NULL);
}
