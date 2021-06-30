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
	if ((philo->number & 1) == 1)
		usleep(500);
	pthread_mutex_lock(philo->is_start);
	pthread_mutex_unlock(philo->is_start);
	philo->last_meal_time = get_timestamp(*philo);
	while (TRUE)
	{
		check_simulation(philo);
		philo->ftake_a_fork(philo, first_fork);
		printf("%d take RIGHT fork\n", philo->number);
		;
		check_simulation(philo);
		philo->ftake_a_fork(philo, second_fork);
		printf("%d take LEFT fork\n", philo->left_fork_number);
		;
		check_simulation(philo);
		philo->feat(philo, philo->opts->time_to_eat);
		check_simulation(philo);
		put_fork(second_fork);
		printf("%d put second_fork\n", philo->number);
		put_fork(first_fork);
		printf("%d put first_fork\n", philo->number);
		check_simulation(philo);
		philo->fsleep(philo, philo->opts->time_to_sleep);
		check_simulation(philo);
		philo->fthink(self);
	}
	return (NULL);
}
