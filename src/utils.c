/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:45:06 by hbernard          #+#    #+#             */
/*   Updated: 2023/06/23 05:32:51 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->table->print);
	if (!has_dead(ph->table))
		printf("%5ld %d %s\n", \
			current_time() - ph->table->time_start, ph->id + 1, msg);
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
