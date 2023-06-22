#include "header.h"

long	get_last_meal(t_philo *ph);
void	check_death(t_philo *ph);
int		get_meal(t_philo *ph);
int		has_dead(t_table *t);

void	*sentinel(void *arg)
{
	int		i;
	t_table	*t;

	i = 0;
	t = arg;
	while (!has_dead(t) && get_meal(&t->philos[i]) != t->num_eats)
	{
		check_death(&t->philos[i]);
		i = (i + 1) % t->philos_qtty;
		usleep(1000);
	}
	return (NULL);
}

void	check_death(t_philo *ph)
{
	t_table	*t;
	long	time;

	t = ph->table;
	pthread_mutex_lock(&t->wait);
	time = current_time() - get_last_meal(ph);
	pthread_mutex_unlock(&t->wait);
	if (time > t->time_die && ph->eating == 0)
	{
		print(ph, "died");
		set_dead(t);
	}
}

int	get_meal(t_philo *ph)
{
	int	meal;

	pthread_mutex_lock(&ph->meal);
	meal = ph->meals;
	pthread_mutex_unlock(&ph->meal);
	return (meal);
}

int	has_dead(t_table *table)
{
	int	status;

	pthread_mutex_lock(&table->dead);
	status = table->has_dead;
	pthread_mutex_unlock(&table->dead);
	return (status);
}