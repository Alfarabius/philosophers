#include "philosophers.h"

void	*start(void *self)
{
	t_philo			*philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	time_t			last_meal_time;

	philo = (t_philo *)self;
	if (philo->right_fork_number > philo->number)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	while (philo->is_alive)
	{
		philo->ftake_a_fork(philo, first_fork);
		philo->ftake_a_fork(philo, second_fork);
		last_meal_time = get_timestamp(*philo);
		if (last_meal_time > philo->opts->time_to_eat)
		{
			philo->fdie(self);
			break ;
		}
		philo->feat(philo, philo->opts->time_to_eat);
		put_fork(first_fork);
		put_fork(second_fork);
		philo->fsleep(philo, philo->opts->time_to_sleep);
		philo->fthink(self);
	}
	return (NULL);
}
