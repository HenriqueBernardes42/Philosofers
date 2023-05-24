#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
//proibidas
#include <string.h>

#define ERR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
 	int				id;
	int				meals;
	long			last_meal;
	t_mutex			*l_fork;
	t_mutex			*r_fork;
	t_mutex			lock;
	t_mutex			meal;
	pthread_t		thread;
	struct s_table	*table;
} t_philo;

typedef struct s_table
{
    int dead;
    int times_need_to_eat;
    int philo_qtty;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    t_mutex *forks;
    t_philo *philos;
} t_table;

//set_things
int     set_init_args(int argc, char **argv, t_table *table);

//libft
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

