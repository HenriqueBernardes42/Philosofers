#include "header.h"

void	print(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->table->print);
	if (!has_dead(ph->table))
		printf("%5ld %d %s\n", current_time() - ph->table->time_start, ph->id + 1, msg);
	pthread_mutex_unlock(&ph->table->print);
}

void	set_last_meal(t_philo *ph)
{
	pthread_mutex_lock(&ph->lock);
	ph->last_meal = current_time();
	pthread_mutex_unlock(&ph->lock);
}

void	ft_free(t_table *t)
{
	int		i;

	i = -1;
	usleep(542);
	while (++i < t->philos_qtty)
	{
		pthread_mutex_destroy(&t->forks[i]);
		pthread_mutex_destroy(&t->philos[i].meal);
		pthread_mutex_destroy(&t->philos[i].lock);
	}
	pthread_mutex_destroy(&t->dead);
	pthread_mutex_destroy(&t->print);
	pthread_mutex_destroy(&t->wait);
	free(t->forks);
	free(t->philos);
}
