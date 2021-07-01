#include "philosophers.h"

void	sleep_(t_philo *self, time_t time_to_sleep)
{
	time_t	time;
	int		number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	pthread_mutex_lock(self->log);
	printf ("%ld %d is sleeping\n", time, number);
	pthread_mutex_unlock(self->log);
	usleep(time_to_sleep * 1000);
}

void	eat(t_philo *self, time_t time_to_eat)
{
	int	number;

	self->last_meal_time = get_timestamp(*self);
	number = self->number;
	pthread_mutex_lock(self->log);
	printf ("%ld %d is eating\n", self->last_meal_time, number);
	pthread_mutex_unlock(self->log);
	usleep(time_to_eat * 1000);
	self->eating_times += 1;
}

void	die(void *self)
{
	time_t	time;
	int		number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	pthread_mutex_lock(((t_philo *)self)->log);
	printf ("%ld %d died\n", time, number);
	pthread_mutex_unlock(((t_philo *)self)->log);
}

void	think(void *self)
{
	time_t	time;
	int		number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	pthread_mutex_lock(((t_philo *)self)->log);
	printf ("%ld %d is thinking\n", time, number);
	pthread_mutex_unlock(((t_philo *)self)->log);
}

void	take_a_fork(t_philo *self, pthread_mutex_t *fork)
{
	time_t	time;
	int		number;

	pick_fork(fork);
	number = self->number;
	time = get_timestamp(*self);
	pthread_mutex_lock(self->log);
	printf ("%ld %d has taken a fork\n", time, number);
	pthread_mutex_unlock(self->log);
	self->forks_taken +=1;
}
