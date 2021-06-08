#include "philosophers.h"

uint8_t	pick_fork(uint8_t **forks, uint64_t number)
{
	uint8_t	*fork;

	fork = forks[number];
	if (fork)
	{
		fork = 0;
		return (1);
	}
	return (0);
}

void	put_fork(uint8_t **forks, uint64_t number)
{
	uint8_t	*fork;

	fork = forks[number];
	fork = 1;
}
