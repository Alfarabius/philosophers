#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define STRING char *
# define TRUE 1
# define FALSE 0
# include <fcntl.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_opts
{
	int		philo_amount;
	int		forks_amount;
	int		eating_times;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
}				t_opts;

typedef struct s_philo
{
	pid_t			pid;
	int				number;
	int				eating_times;
	struct s_sim	*sim;
	time_t			last_meal_time;
	time_t			*start_time;
	void			*(*start)(void*);
	void			(*put_fork)(sem_t *);
	void			(*fsleep)(struct s_philo *, time_t);
	void			(*eat)(struct s_philo *, time_t);
	void			(*die)(struct s_philo *);
	void			(*think)(struct s_philo *);
	void			(*take_a_fork)(struct s_philo *, sem_t *);
	time_t			(*get_time)(struct s_philo);
}					t_philo;

typedef struct s_sim
{
	t_philo			**philo;
	t_opts			*opts;
	time_t			*start_time;
	sem_t			*forks;
	sem_t			*simulation;
	sem_t			*is_start;
}					t_sim;

int			ft_atoi(const char *str);
int			is_not_valid_args(int argc, STRING *argv);
int			error_handler(STRING msg);
int			create_philosophers(t_sim *sim, int amount);
int			create_forks(t_sim *sim, int amount);
void		destroy_forks(sem_t	*forks);
void		destroy_philosophers(t_philo **philo, int amount);
int			parse_options(STRING *args, t_opts *options);
int			start_simulation(t_philo **philo, t_opts *opts, t_sim *sim);
void		*start(void *self);
void		sleep_(t_philo *self, time_t time_to_sleep);
void		eat(t_philo *self, time_t time_to_eat);
void		die(t_philo *self);
void		think(t_philo *self);
void		take_a_fork(t_philo *self, sem_t *fork);
void		pick_fork(sem_t *fork);
void		put_fork(sem_t *fork);
void		ft_delay(time_t pause);
time_t		get_time(void);
time_t		get_timestamp(t_philo philo);
size_t		ft_strlen(STRING str);

#endif
