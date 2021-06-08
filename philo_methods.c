#include "philosophers.h"

void	*sleep_(void *buf)
{
	uint64_t	time;
	uint64_t	number;

	number = ((t_philo *)buf)->number;
	time = get_timestamp(*((t_philo *)buf));
	printf ("%llu %llu is sleeping\n", time, number);
	return (NULL);
}

void	*eat(void *buf)
{
	uint64_t	time;
	uint64_t	number;

	number = ((t_philo *)buf)->number;
	time = get_timestamp(*((t_philo *)buf));
	printf ("%llu %llu is eating\n", time, number);
	return (NULL);
}

void	*die(void *buf)
{
	uint64_t	time;
	uint64_t	number;

	number = ((t_philo *)buf)->number;
	time = get_timestamp(*((t_philo *)buf));
	printf ("%llu %llu is died\n", time, number);
	return (NULL);
}

void	*think(void *buf)
{
	uint64_t	time;
	uint64_t	number;

	number = ((t_philo *)buf)->number;
	time = get_timestamp(*((t_philo *)buf));
	printf ("%llu %llu is thinking\n", time, number);
	return (NULL);
}

void	*take_a_fork(void *buf)
{
	uint64_t	time;
	uint64_t	number;

	number = ((t_philo *)buf)->number;
	time = get_timestamp(*((t_philo *)buf));
	printf ("%llu %llu  has taken a fork\n", time, number);
	return (NULL);
}
