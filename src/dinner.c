#include "header.h"

void	take_a_break(int id);
void	dinner_one(t_philo *ph);

void	*dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->philos_qtty == 1)
	{
		dinner_one(philo);
		return (NULL);
	}
	take_a_break(philo->id);
	while (!has_dead(philo->table) && philo->table->num_eats != philo->meals)
	{
		take_fork(philo);
		eat(philo);
		ph_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	take_a_break(int id)
{
	if (id % 2 == 0)
		usleep(1000);
}

void	dinner_one(t_philo *ph)
{
	pthread_mutex_lock(ph->l_fork);
	print(ph, "has taken a fork");
	pthread_mutex_unlock(ph->l_fork);
	while (!has_dead(ph->table))
		usleep(1000);
}

