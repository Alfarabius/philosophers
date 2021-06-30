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
	int		philo_amount;
	int		forks_amount;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		eating_times;
}				t_opts;

typedef struct s_philo
{
	pthread_t		life;
	int				number;
	int				left_fork_number;
	int				eating_times;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*simulation;
	pthread_mutex_t	*is_start;
	time_t			*start_time;
	time_t			last_meal_time;
	t_opts			*opts;
	void			*(*start)(void*);
	void			(*fsleep)(struct s_philo *, time_t);
	void			(*feat)(struct s_philo *, time_t);
	void			(*fdie)(void *);
	void			(*fthink)(void *);
	void			(*ftake_a_fork)(struct s_philo *, pthread_mutex_t *);
	time_t			(*get_time)(struct s_philo);
}					t_philo;

typedef struct s_sim
{
	t_philo			**philo;
	t_opts			*opts;
	time_t			*start_time;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*simulation;
	pthread_mutex_t	*is_start;
}					t_sim;

int			ft_atoi(const char *str);
int			is_not_valid_args(int argc, STRING *argv);
int			error_handler(STRING msg);
int			create_philosophers(t_sim *sim, int amount);
int			create_forks(t_sim *sim, int amount);
void		destroy_forks(pthread_mutex_t **forks, int amount);
void		destroy_philosophers(t_philo **philo, int amount);
int			parse_options(STRING *args, t_opts *options);
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
