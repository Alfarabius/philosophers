#include "philosophers.h"

static t_philo *create_philosoph(uint64_t number)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo)
	{
		philo->number = number;
		philo->die = die;
		philo->eat = eat;
		philo->sleep = sleep_;
		philo->think = think;
		philo->take_a_fork = take_a_fork;
	}
	return (philo);
}

int	create_philosophers(t_sim *sim, uint64_t amount)
{
	t_philo		*philo;
	t_dlst		*new_ph;
	uint64_t	number;

	number = 1;
	while(amount--)
	{
		philo = create_philosoph(number);
		new_ph = ft_dlst_new((void *)philo);
		if(!philo || !new_ph)
			return (0);
		ft_dlstadd_back(&sim->philo_lst, new_ph);
		number++;
	}
	return (1);
}
