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
	first_fork = philo->right_fork;
	second_fork = philo->left_fork;
	pthread_mutex_lock(philo->is_start);
	pthread_mutex_unlock(philo->is_start);
	philo->last_meal_time = get_timestamp(*philo);
	if ((philo->number & 1) == 0)
		usleep(500);
	while (TRUE)
	{
		check_simulation(philo);
		philo->ftake_a_fork(philo, first_fork);
		pthread_mutex_lock(philo->log);
		printf("\x1B[32m%d\x1B[0m take RIGHT \x1B[31m(#%d)\x1B[0m fork\n", philo->number, philo->number - 1);
		pthread_mutex_unlock(philo->log);
		check_simulation(philo);
		philo->ftake_a_fork(philo, second_fork);
		pthread_mutex_lock(philo->log);
		printf("\x1B[32m%d\x1B[0m take LEFT \x1B[31m(#%d)\x1B[0m fork\n", philo->number, philo->left_fork_number);
		pthread_mutex_unlock(philo->log);
		check_simulation(philo);
		philo->feat(philo, philo->opts->time_to_eat);
		put_fork(second_fork);
		philo->forks_put += 1;
		pthread_mutex_lock(philo->log);
		printf("\x1B[32m%d\x1B[0m put LEFT \x1B[32m(#%d)\x1B[0m fork\n", philo->number, philo->left_fork_number);
		pthread_mutex_unlock(philo->log);
		put_fork(first_fork);
		philo->forks_put += 1;
		pthread_mutex_lock(philo->log);
		printf("\x1B[32m%d\x1B[0m put RIGHT \x1B[32m(#%d)\x1B[0m fork\n", philo->number, philo->number - 1);
		pthread_mutex_unlock(philo->log);
		check_simulation(philo);
		philo->fsleep(philo, philo->opts->time_to_sleep);
		check_simulation(philo);
		philo->fthink(self);
	}
	return (NULL);
}
