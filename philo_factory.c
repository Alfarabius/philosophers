#include "philosophers.h"

static t_philo	*create_philosoph(uint64_t number, uint64_t amount, t_sim sim)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo)
	{
		philo->is_alive = TRUE;
		philo->opts = sim.opts;
		philo->start_time = sim.start_time;
		philo->number = number;
		philo->right_fork_number = (number + 1) % amount;
		philo->left_fork = sim.forks[number];
		philo->right_fork = sim.forks[philo->right_fork_number];
		philo->fdie = die;
		philo->feat = eat;
		philo->fsleep = sleep_;
		philo->fthink = think;
		philo->ftake_a_fork = take_a_fork;
		philo->get_time = get_timestamp;
		philo->start = start;
	}
	return (philo);
}

int	create_philosophers(t_sim *sim, uint64_t amount)
{
	uint64_t	number;
	uint64_t	i;

	number = 0;
	i = amount;
	sim->philo = (t_philo **)malloc(sizeof(t_philo *) * (amount + 1));
	if(!sim->philo)
			return (0);
	while(i--)
	{
		sim->philo[number] = create_philosoph(number + 1, amount, *sim);
		if(!sim->philo[number])
			return (0);
		number++;
	}
	sim->philo[number] = NULL;
	return (1);
}

void	destroy_philosophers(t_philo **philo, uint64_t amount)
{
	while (amount)
	{
		pthread_detach(philo[amount - 1]->life);
		free(philo[amount - 1]);
		amount--;
	}
	free(philo);
}
