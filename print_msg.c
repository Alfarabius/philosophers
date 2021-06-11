#include "philosophers.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	ft_putnbr(int64_t n)
{
	char	show_num[32];
	int		i;

	i = 0;
	if (!n)
		write(1, "0", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	while (n)
	{
		show_num[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	while (i)
		write(1, &show_num[--i], 1);
}

void	print_msg(time_t time, uint64_t number, STRING msg)
{
	ft_putnbr((int64_t)time);
	write(1, " ", 1);
	ft_putnbr((int64_t)number);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));
}
