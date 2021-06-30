#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	error_handler(STRING msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

static int	is_numeric(STRING arg)
{
	while (*arg && (*arg >= '0' && *arg <= '9'))
		arg++;
	if (*arg != 0)
		return (0);
	return (1);
}

int	is_not_valid_args(int argc, STRING *argv)
{
	if (argc != 5 && argc != 6)
		return (error_handler("wrong number of arguments"));
	argv += 1;
	while (*argv)
	{
		if (!is_numeric(*argv))
			return(error_handler("arguments must be numeric"));
		argv++;
	}
	return (0);
}
