#include "header.h"

int	init_thread(t_table *table)
{
	int		i;
	t_philo	*philos;

	if (set_philos(table))
		return (1);
	i = -1;
	philos = table->philos;
	table->time_start = current_time();
	pthread_create(&table->sentinel, NULL, sentinel, table);
	while (++i < table->philos_qtty)
	{
		pthread_mutex_lock(&table->philos[i].lock);
		philos[i].last_meal = table->time_start;
		pthread_mutex_unlock(&table->philos[i].lock);
		pthread_create(&philos[i].thread, NULL, dinner, &philos[i]);
	}
	i = -1;
	while (++i < table->philos_qtty)
		pthread_join(philos[i].thread, NULL);
	pthread_join(table->sentinel, NULL);
	return (0);
}