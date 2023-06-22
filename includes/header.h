# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals;
	long			last_meal;
	t_mutex			*l_fork;
	t_mutex			*r_fork;
	t_mutex			lock;
	t_mutex			meal;
	pthread_t		thread;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int			philos_qtty;
	int			time_sleep;
	int			num_eats;
	int			time_eat;
	int			time_die;
	int			has_dead;
	long		time_start;
	t_mutex		*forks;
	t_mutex		print;
	t_mutex		dead;
	t_mutex		wait;
	t_philo		*philos;
	pthread_t	sentinel;
}	t_table;

int	main(int argc, char **argv);

//SET
int	set_args(int argc, char **argv);
int	set_philos(t_table *table);
void set_table(t_table *table, int argc, char **argv);
int	init_thread(t_table *table);

void	*dinner(void *arg);

//sentinel
void	*sentinel(void *arg);
int		has_dead(t_table *t);
void	set_dead(t_table *t);


//time
long	current_time(void);

//actions
void	take_fork(t_philo *ph);
void	eat(t_philo *ph);
void	think(t_philo *ph);
void	set_meal(t_philo *ph);
void	ph_sleep(t_philo *ph);

//libft
int		ft_isdigit(int c);
int		ft_atoi(const char	*str);

//utils
void	print(t_philo *ph, char *msg);
void	set_last_meal(t_philo *ph);
void	ft_free(t_table *t);


