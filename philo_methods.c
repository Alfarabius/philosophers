#include "philosophers.h"

void	*sleep(void *buf)
{
	printf ("%s\n", (STRING)buf);
	return (NULL);
}

void	*eat(void *buf)
{
	printf ("%s\n", (STRING)buf);
	return (NULL);
}

void	*die(void *buf)
{
	printf ("%s\n", (STRING)buf);
	return (NULL);
}

void	*think(void *buf)
{
	printf ("%s\n", (STRING)buf);
	return (NULL);
}

void	*take_a_fork(void *buf)
{
	printf ("%s\n", (STRING)buf);
	return (NULL);
}
