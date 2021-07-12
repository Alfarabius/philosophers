#include "philosophers.h"

static void	check_simulation(sem_t *sim)
{
	sem_wait(sim);
	sem_post(sim);
}

void	*start(void *self)
{
	t_philo			*philo;

	philo = (t_philo *)self;
	sem_wait(philo->sim->is_start);
	sem_post(philo->sim->is_start);
	philo->last_meal_time = get_timestamp(*philo);
	if ((philo->number & 1) == 0)
		ft_delay(philo->sim->opts->time_to_sleep);
	while (TRUE)
	{
		check_simulation(philo->sim->simulation);
		philo->take_a_fork(philo, philo->sim->forks);
		check_simulation(philo->sim->simulation);
		philo->take_a_fork(philo, philo->sim->forks);
		check_simulation(philo->sim->simulation);
		philo->eat(philo, philo->sim->opts->time_to_eat);
		philo->put_fork(philo->sim->forks);
		philo->put_fork(philo->sim->forks);
		check_simulation(philo->sim->simulation);
		philo->fsleep(philo, philo->sim->opts->time_to_sleep);
		check_simulation(philo->sim->simulation);
		philo->think(self);
	}
	return (NULL);
}
