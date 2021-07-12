#include "philosophers.h"

void	pick_fork(sem_t *fork)
{
	sem_wait(fork);
}

void	put_fork(sem_t *fork)
{
	sem_post(fork);
}

int	create_forks(t_sim *sim, int am)
{
	sem_unlink("forks");
	sim->forks = (sem_t *)malloc(sizeof(sem_t));
	if (!sim->forks)
		return (0);
	sim->forks = sem_open("forks", O_CREAT, 0755, am);
	if (sim->forks == SEM_FAILED)
		return (0);
	return (1);
}

void	destroy_forks(sem_t	*forks)
{
	sem_close(forks);
}
