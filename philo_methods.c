#include "philosophers.h"

void	sleep_(t_philo *self, time_t time_to_sleep)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is sleeping\n", time, number);
	//print_msg(time, number, " is sleeping\n");
	usleep(time_to_sleep * 1000);
}

void	eat(t_philo *self, time_t time_to_eat)
{
	time_t		time;
	uint64_t	number;

	number = self->number;
	time = get_timestamp(*self);
	printf ("%ld %llu is eating\n", time, number);
	//print_msg(time, number, " is eating\n");
	usleep(time_to_eat * 1000);
}

void	die(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is died\n", time, number);
	//print_msg(time, number, " is died\n");
	((t_philo *)self)->is_alive = FALSE;
	**((t_philo *)self)->dead = TRUE;
}

void	think(void *self)
{
	time_t		time;
	uint64_t	number;

	number = ((t_philo *)self)->number;
	time = get_timestamp(*((t_philo *)self));
	printf ("%ld %llu is thinking\n", time, number);
	//print_msg(time, number, " is thinking\n");
}

void	take_a_fork(t_philo *self, pthread_mutex_t *fork)
{
	time_t		time;
	uint64_t	number;

	number = self->number;
	time = get_timestamp(*self);
	pick_fork(fork);
	printf ("%ld %llu has taken a fork\n", time, number);
	//print_msg(time, number, " has taken a fork\n");
}
