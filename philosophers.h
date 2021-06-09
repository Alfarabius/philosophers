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
	pthread_t		life;
	uint64_t		number;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	time_t			*start_time;
	void			*(*start)(void*);
	void			*(*fsleep)(void *);
	void			*(*feat)(void *);
	void			*(*fdie)(void *);
	void			*(*fthink)(void *);
	void			*(*ftake_a_fork)(void *);
	time_t			(*get_time)(struct s_philosopher);
}					t_philo;

typedef struct s_sim
{
	t_philo			**philo;
	t_opts			*opts;
	time_t			*start_time;
	pthread_mutex_t	**forks;
}					t_sim;

int64_t		ft_atoi(const char *str);
int			is_not_valid_args(int argc, STRING *argv);
int			error_handler(STRING msg);
int			create_philosophers(t_sim *sim, uint64_t amount);
int			create_forks(t_sim *sim, uint64_t amount);
void		destroy_forks(pthread_mutex_t **forks, uint64_t amount);
void		destroy_philosophers(t_philo **philo, uint64_t amount);
void		parse_options(STRING *args, t_opts *options);
void		start_simulation(t_sim *sim);
void		*start(void *self);
void		*sleep_(void *self);
void		*eat(void *self);
void		*die(void *self);
void		*think(void *self);
void		*take_a_fork(void *self);
void		pick_fork(pthread_mutex_t *fork);
void		put_fork(pthread_mutex_t *fork);
time_t		get_timestamp(t_philo philo);

#endif
