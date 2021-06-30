#include "philosophers.h"

static	int	init_simulation(t_sim *sim, t_opts *opts)
{
	struct timeval	*time;

	time = (struct timeval *)malloc(sizeof(struct timeval));
	sim->start_time = (time_t *)malloc(sizeof(time_t));
	sim->simulation = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	sim->is_start = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!time || !sim->simulation || !sim->start_time || !sim->is_start)
		return (0);
	pthread_mutex_init(sim->simulation, NULL);
	pthread_mutex_init(sim->is_start, NULL);
	pthread_mutex_lock(sim->is_start);
	gettimeofday(time, NULL);
	*sim->start_time = (time->tv_usec / 1000) + (time->tv_sec * 1000);
	sim->philo = NULL;
	sim->opts = opts;
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
