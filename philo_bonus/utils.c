#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int64_t	result;
	int		sign;
	int		i;

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
	if (result > 2147483648 && sign == -1)
		return (0);
	else if (result > 2147483647)
		return (-1);
	return ((int)result * sign);
}

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

time_t	get_timestamp(t_philo philo)
{
	return (get_time() - *philo.sim->start_time);
}

void	ft_delay(time_t pause)
{
	time_t	start_time;

	start_time = get_time();
	while (get_time() - start_time < pause)
		usleep(500);
}

size_t	ft_strlen(STRING str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
