#include "philosophers.h"

void	pick_fork(pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
}

void	put_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

int	create_forks(t_sim *sim, uint64_t amount)
{
	uint64_t		i;
	int				err;

	sim->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * (amount + 1));
	if (!sim->forks)
		return (0);
	i = 0;
	while (i < amount)
	{
		sim->forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		err = pthread_mutex_init(sim->forks[i], NULL);
		if (!sim->forks[i] || err)
			return(0);
		i++;
	}
	sim->forks[amount] = NULL;
	return (1);
}

void	destroy_forks(pthread_mutex_t **forks, uint64_t amount)
{
	pthread_mutex_t	*fork;

	while (amount)
	{
		fork = forks[amount - 1];
		pthread_mutex_destroy(fork);
		free(fork);
		amount--;
	}
	free(forks);
}
