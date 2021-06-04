#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define STRING char *
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_opts
{
	uint64_t	philo_amount;
	uint64_t	forks_amount;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	eating_times;
}				t_opts;

typedef struct s_dlst
{
	void			*content;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct s_philo
{
	uint64_t		number;
	void			*sleep;
	void			*eat;
	void			*die;
	void			*think;
	void			*take_a_fork;
}				t_philo;

typedef struct s_sim
{
	t_dlst	*philo_lst;
	t_opts	*opts;
}				t_sim;

int64_t	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
t_dlst	*ft_dlst_new(void *content);
t_dlst	*ft_dlstlast(t_dlst *dlst);
void	ft_dlstadd_back(t_dlst **dlst, t_dlst *new);
void	ft_dlstclear(t_dlst **dlst, void (*del)(void*));
int		ft_dlstsize(t_dlst *dlst);
int		is_not_valid_args(int argc, STRING *argv);
int		error_handler(STRING msg);
int		create_philosophers(t_sim *sim, uint64_t amount);
void	parse_options(STRING *args, t_opts *options);
void	start_simulation(t_sim *sim);
void	*sleep_(void *buf);
void	*eat(void *buf);
void	*die(void *buf);
void	*think(void *buf);
void	*take_a_fork(void *buf);

#endif
