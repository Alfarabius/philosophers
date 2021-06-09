#include "philosophers.h"

void	*sleep_(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is sleeping\n", time, number);
	return (NULL);
}

void	*eat(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is eating\n", time, number);
	return (NULL);
}

void	*die(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is died\n", time, number);
	return (NULL);
}

void	*think(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is thinking\n", time, number);
	return (NULL);
}

void	*take_a_fork(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu  has taken a fork\n", time, number);
	return (NULL);
}
