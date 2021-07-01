#include "philosophers.h"

static	void	statistic(t_sim sim)
{
	int	eating_times = 0;
	int	forks_taken = 0;
	int	forks_put = 0;
	int	amount;

	amount = sim.opts->philo_amount;
	while(amount)
	{
		eating_times += sim.philo[amount - 1]->eating_times;
		forks_taken += sim.philo[amount - 1]->forks_taken;
		forks_put += sim.philo[amount - 1]->forks_put;
		amount--;
	}
	printf("et = %d, ft = %d, fp = %d\n", eating_times, forks_taken, forks_put);
	printf("%d if not zero some error\n", eating_times / (forks_put * 2));
	printf("%d = %d ?\n", forks_taken - forks_put, sim.opts->philo_amount);
}

static	int	init_simulation(t_sim *sim, t_opts *opts)
{
	struct timeval	*time;

	time = (struct timeval *)malloc(sizeof(struct timeval));
	sim->start_time = (time_t *)malloc(sizeof(time_t));
	sim->simulation = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	sim->is_start = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	sim->log = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!time || !sim->simulation || !sim->start_time || !sim->is_start || !sim->log)
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

	printf("\x1B[34m____________________________Philosophers____________________________\x1B[0m\n");
	if (is_not_valid_args(argc, argv))
		return (1);
	if (!parse_options(argv, &options))
		return (error_handler("too big, negative or zero argument"));
	if (!init_simulation(&simul, &options) || \
	!create_forks(&simul, options.forks_amount) || \
	!create_philosophers(&simul, options.philo_amount))
		return (error_handler("memmory doesn't allocated"));
	start_simulation(simul.philo, simul.opts, &simul);
	statistic(simul);
	destroy_simulation(&simul, options);
	return (0);
}
