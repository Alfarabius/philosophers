#include "philosophers.h"

static t_philo	*create_philosoph(int number, int amount, t_sim sim)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo)
	{
		philo->eating_times = 0;
		philo->simulation = sim.simulation;
		philo->opts = sim.opts;
		philo->start_time = sim.start_time;
		philo->number = number + 1;
		philo->priority = philo->number & 1;
		philo->left_fork_number = (number + 1) % amount;
		philo->right_fork = sim.forks[number];
		philo->left_fork = sim.forks[philo->left_fork_number];
		philo->is_start = sim.is_start;
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

int	create_philosophers(t_sim *sim, int amount)
{
	int	number;
	int	i;

	number = 0;
	i = amount;
	sim->philo = (t_philo **)malloc(sizeof(t_philo *) * (amount + 1));
	if(!sim->philo)
			return (0);
	while(i--)
	{
		sim->philo[number] = create_philosoph(number, amount, *sim);
		if(!sim->philo[number])
			return (0);
		number++;
	}
	sim->philo[number] = NULL;
	return (1);
}

void	destroy_philosophers(t_philo **philo, int amount)
{
	while (amount)
	{
		pthread_detach(philo[amount - 1]->life);
		free(philo[amount - 1]);
		amount--;
	}
	free(philo);
}
