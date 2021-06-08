#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define STRING char *
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_opts
{
	uint64_t	philo_amount;
	uint64_t	forks_amount;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	eating_times;
}				t_opts;

typedef struct s_philosopher
{
	uint64_t	number;
	uint64_t	left_fork;
	uint64_t	right_fork;
	time_t		*start_time;
	void		*(*fsleep)(void *);
	void		*(*feat)(void *);
	void		*(*fdie)(void *);
	void		*(*fthink)(void *);
	void		*(*ftake_a_fork)(void *);
	time_t		(*get_time)(struct s_philosopher);
}				t_philo;

typedef struct s_sim
{
	t_philo		**philo;
	t_opts		*opts;
	time_t		*start_time;
	uint8_t		*forks;
}				t_sim;

int64_t		ft_atoi(const char *str);
int			is_not_valid_args(int argc, STRING *argv);
int			error_handler(STRING msg);
int			create_philosophers(t_sim *sim, uint64_t amount);
void		parse_options(STRING *args, t_opts *options);
void		start_simulation(t_sim *sim);
void		*sleep_(void *buf);
void		*eat(void *buf);
void		*die(void *buf);
void		*think(void *buf);
void		*take_a_fork(void *buf);
void		put_fork(uint8_t **forks, uint64_t number);
uint8_t		pick_fork(uint8_t **forks, uint64_t number);
time_t		get_timestamp(t_philo philo);

#endif
