#include "philosophers.h"

static int	is_dead(t_philo *philo)
{
	if (get_timestamp(*philo) - philo->last_meal_time > \
		philo->opts->time_to_die)
		{
			philo->fdie((void *)philo);
			return (TRUE);
		}
	return (FALSE);
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
	while (!*philo->is_start);
	philo->last_meal_time = *philo->start_time;
	while (philo->is_alive)
	{
		philo->ftake_a_fork(philo, first_fork);
		philo->ftake_a_fork(philo, second_fork);
		if (is_dead(philo))
			break ;
		philo->feat(philo, philo->opts->time_to_eat);
		philo->last_meal_time = get_timestamp(*philo);
		put_fork(second_fork);
		put_fork(first_fork);
		philo->fsleep(philo, philo->opts->time_to_sleep);
		philo->fthink(self);
	}
	return (NULL);
}
