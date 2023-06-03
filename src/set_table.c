#include "header.h"

void set_table(t_table *table, int argc, char **argv)
{
	table->has_dead = 0;
	table->num_eats = -42; //MUDAR
	table->n_philos = ft_atoi(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->tm_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->num_eats = ft_atoi(argv[5]);
	table->forks = malloc(table->n_philos * sizeof(t_mutex));
	table->philos = malloc(table->n_philos * sizeof(t_philo));
}