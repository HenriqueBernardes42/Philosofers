/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:44:26 by hbernard          #+#    #+#             */
/*   Updated: 2023/06/24 15:42:37 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pthread_mutex_lock(&ph->meal);
	ph->meals++;
	pthread_mutex_unlock(&ph->meal);
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
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(ph->l_fork);
	if (!has_dead(ph->table))
	{
		print(ph, "is sleeping");
		usleep(ph->table->time_sleep * 1000);
	}
}
