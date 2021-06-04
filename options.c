#include "philosophers.h"

void	parse_options(STRING *args, t_opts *options)
{
	options->philo_amount = ft_atoi(args[1]);
	options->forks_amount = options->philo_amount;
	options->time_to_die = ft_atoi(args[2]);
	options->time_to_eat = ft_atoi(args[3]);
	options->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		options->eating_times = ft_atoi(args[5]);
}
