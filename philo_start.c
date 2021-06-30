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
	if ((philo->number & 1) == 0)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
		usleep(100);
	}
	pthread_mutex_lock(philo->is_start);
	pthread_mutex_unlock(philo->is_start);
	philo->last_meal_time = get_timestamp(*philo);
	while (TRUE)
	{
		check_simulation(philo);
		// int f = 0;
		// while (!philo->priority)
		// {
		// 	// if (!f)
		// 	// {
		// 	// 	printf("i'am %d, my priority is %d WAIT!!!\n", philo->number, philo->priority);
		// 	// 	;
		// 	// 	f = 1;
		// 	// }
		// }
		philo->ftake_a_fork(philo, first_fork);
		// first_fork == philo->left_fork ? printf("%d take LEFT fork\n", philo->number) : printf("%d take RIGHT fork\n", philo->number);
		// ;
		check_simulation(philo);
		philo->ftake_a_fork(philo, second_fork);
		// second_fork == philo->left_fork ? printf("%d take LEFT fork\n", philo->number) : printf("%d take RIGHT fork\n", philo->number);
		// ;
		check_simulation(philo);
		//printf("i'am %d, my priority is %d START!!!\n", philo->number, philo->priority);
		philo->feat(philo, philo->opts->time_to_eat);
		check_simulation(philo);
		put_fork(second_fork);
		// printf("%d put second_fork\n", philo->number);
		put_fork(first_fork);
		// printf("%d put first_fork\n", philo->number);
		check_simulation(philo);
		philo->fsleep(philo, philo->opts->time_to_sleep);
		check_simulation(philo);
		philo->fthink(self);
	}
	return (NULL);
}
