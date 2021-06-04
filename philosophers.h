#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define STRING char *
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_opts
{
	uint64_t	philo_amount;
	uint64_t	forks_amount;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	eating_times;
}				t_opts;

typedef struct s_philo
{
	uint64_t		number;
	void			*sleep;
	void			*eat;
	void			*die;
	void			*think;
	void			*take_a_fork;
	struct s_philo	*next;
	struct s_philo	*prev;
}				t_philo;

typedef struct s_sim
{
	t_philo	*philo_lst;
	t_opts	*opts;
}				t_sim;

int64_t	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		is_not_valid_args(int argc, STRING *argv);
void	parse_options(STRING *args, t_opts *options);

#endif
