#include "philosophers.h"

int64_t	ft_atoi(const char *str)
{
	uint64_t	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (result > 9223372036854775807 && sign == -1)
		return (0);
	else if (result > 9223372036854775807)
		return (-1);
	return ((int64_t)result * sign);
}

time_t	get_timestamp(t_philo philo)
{
	struct timeval	time;
	time_t			curr;

	gettimeofday(&time, NULL);
	curr = time.tv_usec - *philo.start_time;
	return (curr / 1000);
}
