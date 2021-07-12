#include "philosophers.h"

static t_philo	*create_philosoph(int number, t_sim *sim)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo)
	{
		philo->sim = sim;
		philo->eating_times = 0;
		philo->sim->simulation = sim->simulation;
		philo->number = number + 1;
		philo->sim->is_start = sim->is_start;
		philo->die = die;
		philo->eat = eat;
		philo->fsleep = sleep_;
		philo->think = think;
		philo->take_a_fork = take_a_fork;
		philo->get_time = get_timestamp;
		philo->start = start;
		philo->put_fork = put_fork;
	}
	return (philo);
}

int	create_philosophers(t_sim *sim, int amount)
{
	int	number;
	int	i;

	number = 0;
	i = amount;
	sim->philo = (t_philo **)malloc(sizeof(t_philo *) * (amount));
	if (!sim->philo)
		return (0);
	while (i--)
	{
		sim->philo[number] = create_philosoph(number, sim);
		if (!sim->philo[number])
			return (0);
		number++;
	}
	return (1);
}

void	destroy_philosophers(t_philo **philo, int amount)
{
	while (amount)
	{
		kill(philo[amount - 1]->pid, SIGKILL);
		free(philo[amount - 1]);
		amount--;
	}
	free(philo);
}
