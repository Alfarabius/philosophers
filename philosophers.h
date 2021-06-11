#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define STRING char *
# define TRUE 1
# define FALSE 0
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
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	uint64_t	eating_times;
}				t_opts;

typedef struct s_philo
{
	uint8_t			is_alive;
	pthread_t		life;
	uint64_t		number;
	uint64_t		left_fork_number;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	uint8_t			**dead;
	time_t			*start_time;
	t_opts			*opts;
	void			*(*start)(void*);
	void			(*fsleep)(struct s_philo *, time_t);
	void			(*feat)(struct s_philo *, time_t);
	void			(*fdie)(void *);
	void			(*fthink)(void *);
	void			(*ftake_a_fork)(struct s_philo *, pthread_mutex_t *);
	time_t			(*get_time)(struct s_philo);
	uint8_t			*is_start;
}					t_philo;

typedef struct s_sim
{
	uint8_t			is_start;
	t_philo			**philo;
	t_opts			*opts;
	time_t			*start_time;
	pthread_mutex_t	**forks;
	uint8_t			someone_dead;
}					t_sim;

int64_t		ft_atoi(const char *str);
int			is_not_valid_args(int argc, STRING *argv);
int			error_handler(STRING msg);
int			create_philosophers(t_sim *sim, uint64_t amount);
int			create_forks(t_sim *sim, uint64_t amount);
void		print_msg(time_t time, uint64_t number, STRING msg);
void		destroy_forks(pthread_mutex_t **forks, uint64_t amount);
void		destroy_philosophers(t_philo **philo, uint64_t amount);
void		parse_options(STRING *args, t_opts *options);
void		start_simulation(t_philo **philo, t_opts *opts, t_sim *sim);
void		*start(void *self);
void		sleep_(t_philo *self, time_t time_to_sleep);
void		eat(t_philo *self, time_t time_to_eat);
void		die(void *self);
void		think(void *self);
void		take_a_fork(t_philo *self, pthread_mutex_t *fork);
void		pick_fork(pthread_mutex_t *fork);
void		put_fork(pthread_mutex_t *fork);
time_t		get_timestamp(t_philo philo);

#endif
