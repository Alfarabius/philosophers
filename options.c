#include "philosophers.h"

int	parse_options(STRING *args, t_opts *options)
{
	int	err;

	err = 0;
	err |= options->philo_amount = ft_atoi(args[1]);
	err |= options->forks_amount = options->philo_amount;
	err |= options->time_to_die = ft_atoi(args[2]);
	err |= options->time_to_eat = ft_atoi(args[3]);
	err |= options->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		err |= options->eating_times = ft_atoi(args[5]);
	else
		options->eating_times = -2;
	if (err == -1 || err == 0)
		return (0);
	return (1);
}
