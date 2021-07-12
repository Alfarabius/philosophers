#include "philosophers.h"

void	sleep_(t_philo *self, time_t time_to_sleep)
{
	time_t	time;
	int		number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %d is sleeping\n", time, number);
	ft_delay(time_to_sleep);
}

void	eat(t_philo *self, time_t time_to_eat)
{
	int	number;

	self->last_meal_time = get_timestamp(*self);
	number = self->number;
	printf ("%ld %d is eating\n", self->last_meal_time, number);
	ft_delay(time_to_eat);
	self->eating_times += 1;
}

void	die(t_philo *self)
{
	time_t	time;
	int		number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*self);
	printf ("%ld %d died\n", time, number);
}

void	think(t_philo *self)
{
	time_t	time;
	int		number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*self);
	printf ("%ld %d is thinking\n", time, number);
}

void	take_a_fork(t_philo *self, sem_t *fork)
{
	time_t	time;
	int		number;

	pick_fork(fork);
	number = self->number;
	time = get_timestamp(*self);
	printf ("%ld %d has taken a fork\n", time, number);
}
