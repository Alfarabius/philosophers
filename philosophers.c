#include "philosophers.h"

/* 1)number_of_philosophers 2)time_to_die 3)time_to_eat
4)time_to_sleep 5)[number_of_times_each_philosopher_must_eat] */

void	init_simulation(t_sim *sim, t_opts *opts)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	*sim->start_time = time.tv_usec;
	sim->philo = NULL;
	sim->opts = opts;
}

int	main(int argc, STRING *argv)
{
	t_opts	options;
	t_sim	simul;

	if (is_not_valid_args(argc, argv))
		return (1);
	parse_options(argv, &options);
	init_simulation(&simul, &options);
	if (!create_philosophers(&simul, options.philo_amount))
		return (error_handler("memmory doesn't allocated"));
	start_simulation(&simul);
	return (0);
}
