#include "philosophers.h"

static void	*dead(int dead, t_philo *philo, t_sim *sim)
{
	if (dead)
		philo->die((void *)philo);
	sem_wait(sim->simulation);
	return (NULL);
}

static void	*dead_checker(void *sim)
{
	int			amount;
	int			fill;
	t_philo		*philo;
	time_t		pause;

	while (TRUE)
	{
		usleep(100);
		amount = ((t_sim *)sim)->opts->philo_amount;
		fill = 1;
		while (amount--)
		{
			philo = ((t_sim *)sim)->philo[amount];
			pause = get_timestamp(*philo) - philo->last_meal_time;
			if (pause >= philo->sim->opts->time_to_die)
				return (dead(TRUE, philo, ((t_sim *)sim)));
			if (((t_sim *)sim)->opts->eating_times != -2 && \
				philo->eating_times < ((t_sim *)sim)->opts->eating_times)
				fill &= 0;
		}
		if (((t_sim *)sim)->opts->eating_times != -2 && fill == 1)
			return (dead(FALSE, philo, sim));
	}
	return (NULL);
}

int	start_simulation(t_philo **philo, t_opts *opts, t_sim *sim)
{
	int				num;

	num = -1;
	while (++num < opts->philo_amount)
	{
		philo[num]->pid = fork();
		if (philo[num]->pid == -1)
			return (error_handler("error during fork"));
		if (philo[num]->pid == 0)
			start((void *)philo[num]);

	}
	*sim->start_time = get_time();
	sem_post(sim->is_start);
	dead_checker((void *)sim);
	return (1);
}
