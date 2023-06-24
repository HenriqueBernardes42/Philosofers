/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:44:56 by hbernard          #+#    #+#             */
/*   Updated: 2023/06/22 15:46:12 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (++i < table->philos_qtty)
	{
		table->philos[i].id = i;
		table->philos[i].meals = 0;
		table->philos[i].last_meal = current_time();
		table->philos[i].l_fork = &table->forks[i];
		table->philos[i].r_fork = &table->forks[(i + 1) % table->philos_qtty];
		table->philos[i].eating = 0;
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
	while (++i < table->philos_qtty)
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
