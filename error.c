#include "philosophers.h"

int	error_handler(STRING msg)
{
	printf("%s\n", msg);
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
