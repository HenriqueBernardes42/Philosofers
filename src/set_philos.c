#include "header.h"

static int	set_mutex(t_table *table);

int	set_philos(t_table *table)
{
	int	i;

	if (!table->philos || !table->forks)
	{
		printf("Malloc error\n");
		return (1);
	}
	if (set_mutex(table))
		return (1);
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].id = i;
		table->philos[i].meals = 0;
		table->philos[i].last_meal = now();
		table->philos[i].l_fork = &table->forks[i];
		table->philos[i].r_fork = &table->forks[(i + 1) % table->n_philos];
		table->philos[i].table = table;
		pthread_mutex_init(&table->philos[i].lock, NULL);
		pthread_mutex_init(&table->philos[i].meal, NULL);
	}
	return (0);
}

static int	set_mutex(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			printf("Error: mutex init\n");
			return (1);
		}
	}
	if (pthread_mutex_init(&table->print, NULL)
		|| pthread_mutex_init(&table->dead, NULL)
		|| pthread_mutex_init(&table->wait, NULL))
	{
		printf("Error: mutex init\n");
		return (1);
	}
	return (0);
}