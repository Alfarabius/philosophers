#include "philosophers.h"

static t_philo *create_philosoph(uint64_t number, uint64_t amount, t_sim sim)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo)
	{
		philo->start_time = &sim.start_time;
		philo->number = number;
		philo->left_fork = number;
		philo->right_fork = (number + 1) % amount;
		philo->fdie = die;
		philo->feat = eat;
		philo->fsleep = sleep_;
		philo->fthink = think;
		philo->ftake_a_fork = take_a_fork;
		philo->get_time = get_timestamp;
	}
	return (philo);
}

int	create_philosophers(t_sim *sim, uint64_t amount)
{
	uint64_t	number;
	uint64_t	i;

	number = 0;
	i = amount;
	sim->forks = (uint8_t *)malloc(sizeof(uint8_t) * amount);
	sim->philo = (t_philo **)malloc(sizeof(t_philo *) * amount + 1);
	if(!sim->philo || !sim->forks)
			return (0);
	memset(sim->forks, '1', amount);
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
