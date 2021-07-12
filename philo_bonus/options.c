#include "philosophers.h"

int	parse_options(STRING *args, t_opts *options)
{
	options->philo_amount = ft_atoi(args[1]);
	options->time_to_die = ft_atoi(args[2]);
	options->time_to_eat = ft_atoi(args[3]);
	options->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		options->eating_times = ft_atoi(args[5]);
	else
		options->eating_times = -2;
	if (options->philo_amount == -1 || options->philo_amount == 0 || \
	options->time_to_die == -1 || options->time_to_die == 0 || \
	options->time_to_eat == -1 || options->time_to_eat == 0 || \
	options->time_to_sleep == -1 || options->time_to_sleep == 0 || \
	options->eating_times == -1 || options->eating_times == 0)
		return (0);
	return (1);
}
