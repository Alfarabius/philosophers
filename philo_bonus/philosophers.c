#include "philosophers.h"

static	int	init_simulation(t_sim *sim, t_opts *opts)
{
	sem_unlink("simulation");
	sem_unlink("start");
	sim->simulation = (sem_t *)malloc(sizeof(sem_t));
	sim->is_start = (sem_t *)malloc(sizeof(sem_t));
	if (!sim->simulation || !sim->is_start)
		return (0);
	sim->simulation = sem_open("simulation", O_CREAT, 0755, 1);
	sim->is_start = sem_open("start", O_CREAT, 0755, 1);
	if (sim->simulation == SEM_FAILED || sim->is_start == SEM_FAILED)
		return (0);
	sem_wait(sim->is_start);
	sim->philo = NULL;
	sim->opts = opts;
	return (1);
}

static	void	destroy_simulation(t_sim *sim, t_opts opts)
{
	destroy_philosophers(sim->philo, opts.philo_amount);
	destroy_forks(sim->forks);
	sem_close(sim->is_start);
	sem_close(sim->simulation);
}

int	main(int argc, STRING *argv)
{
	t_opts	options;
	t_sim	simul;

	if (is_not_valid_args(argc, argv))
		return (1);
	if (!parse_options(argv, &options))
		return (error_handler("too big, negative or zero argument"));
	if (!init_simulation(&simul, &options) || \
	!create_forks(&simul, options.philo_amount) || \
	!create_philosophers(&simul, options.philo_amount))
		return (error_handler("memmory doesn't allocated"));
	if (!start_simulation(simul.philo, simul.opts, &simul))
		return (1);
	destroy_simulation(&simul, options);
	return (0);
}
