#include "header.h"

void	set_dead(t_table *t)
{
	pthread_mutex_lock(&t->dead);
	t->has_dead = 1;
	pthread_mutex_unlock(&t->dead);
}

long	get_last_meal(t_philo *ph)
{
	long	l_meal;

	pthread_mutex_lock(&ph->lock);
	l_meal = ph->last_meal;
	pthread_mutex_unlock(&ph->lock);
	return (l_meal);
}