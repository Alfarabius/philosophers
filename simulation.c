#include "philosophers.h"

void	start_simulation(t_sim *sim)
{
	uint8_t		simulation_is_running;
	uint64_t	i;

	i = 1000;
	(void)sim;
	simulation_is_running = 1;
	while(simulation_is_running)
	{
		while (i--)
			(*(sim->philo[0]->feat))(sim->philo[0]);
		simulation_is_running = 0;
	}
}
