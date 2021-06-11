#include "philosophers.h"

/* 1)number_of_philosophers 2)time_to_die 3)time_to_eat
4)time_to_sleep 5)[number_of_times_each_philosopher_must_eat] */

static	int	init_simulation(t_sim *sim, t_opts *opts)
{
	struct timeval	*time;

	time = (struct timeval *)malloc(sizeof(struct timeval));
	if (!time)
		return (0);
	gettimeofday(time, NULL);
	*sim->start_time = (time->tv_usec / 1000) + (time->tv_sec * 1000);
	sim->someone_dead = FALSE;
	sim->philo = NULL;
	sim->opts = opts;
	sim->is_start = FALSE;
	free(time);
	return (1);
}

static	void	destroy_simulation(t_sim *sim, t_opts opts)
{
	destroy_philosophers(sim->philo, opts.philo_amount);
	destroy_forks(sim->forks, opts.forks_amount);
}

int	main(int argc, STRING *argv)
{
	t_opts	options;
	t_sim	simul;

	if (is_not_valid_args(argc, argv))
		return (1);
	parse_options(argv, &options);
	if (!init_simulation(&simul, &options) || \
	!create_forks(&simul, options.forks_amount) || \
	!create_philosophers(&simul, options.philo_amount))
		return (error_handler("memmory doesn't allocated"));
	start_simulation(simul.philo, simul.opts, &simul);
	destroy_simulation(&simul, options);
	return (0);
}
