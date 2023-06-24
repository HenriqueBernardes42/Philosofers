/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentinel_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:44:47 by hbernard          #+#    #+#             */
/*   Updated: 2023/06/23 05:31:58 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
