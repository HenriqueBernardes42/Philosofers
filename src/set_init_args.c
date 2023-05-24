#include "header.h"

static int check_args_qntty(int argc);
static void set_struct(int argc, char **argv, t_table *table);
static int check_digits(char **argv);


int set_init_args(int argc, char **argv, t_table *table)
{
    if(!check_args_qntty(argc))
        return (ERR);
    check_digits(argv);
    set_struct(argc, argv, table);
    return (OK);
}

static int check_args_qntty(int argc)
{
    if(argc != 5 && argc != 6)
    {
        printf("FAIL: wrong number of args\n");
        return (ERR);
    }
    return (OK);
}

static int check_digits(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
        {
            if(ft_isdigit(argv[i][j]) == FALSE)
            {
                printf("'%c' char detected!!!\n", argv[i][j]);
                printf("FAIL: numeric argument required\n");
                return (ERR);
            }
        }
    }
    return (OK);
}

static void set_struct(int argc, char **argv, t_table  *table)
{  
    table->dead = FALSE;
    table->philo_qtty = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if(argc == 6)
        table->times_need_to_eat = ft_atoi(argv[5]);
    else
        table->times_need_to_eat = -1;
    table->forks = malloc(table->philo_qtty * sizeof(t_mutex));
	table->philos = malloc(table->philo_qtty * sizeof(t_philo));
}