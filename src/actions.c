#include "header.h"

void	take_fork(t_philo *ph)
{
	if (!has_dead(ph->table))
	{
		if (ph->id % 2)
		{
			pthread_mutex_lock(ph->l_fork);
			print(ph, "has taken a l_fork");
			pthread_mutex_lock(ph->r_fork);
			print(ph, "has taken a r_fork");
		}
		else
		{
			pthread_mutex_lock(ph->r_fork);	
			print(ph, "has taken a r_fork");
			pthread_mutex_lock(ph->l_fork);
			print(ph, "has taken a l_fork");
		}
	}
}

void	set_meal(t_philo *ph)
{
	ph->meals++;
}

void	eat(t_philo *ph)
{
	if (!has_dead(ph->table))
	{
		print(ph, "is eating");
		set_meal(ph);
		ph->eating = 1;
		set_last_meal(ph);
		usleep(ph->table->time_eat * 1000);
		ph->eating = 0;
	}
}

void	think(t_philo *ph)
{
	if (!has_dead(ph->table))
	{
		print(ph, "is thinking");
	}
}

void	ph_sleep(t_philo *ph)
{
	if (!has_dead(ph->table))
	{
		print(ph, "is sleeping");
		pthread_mutex_unlock(ph->r_fork);
		pthread_mutex_unlock(ph->l_fork);
		usleep(ph->table->time_sleep * 1000);
	}
}
