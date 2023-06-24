/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:44:59 by hbernard          #+#    #+#             */
/*   Updated: 2023/06/22 15:47:57 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_table(t_table *table, int argc, char **argv)
{
	table->has_dead = 0;
	table->num_eats = -1;
	table->philos_qtty = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->num_eats = ft_atoi(argv[5]);
	table->forks = malloc(table->philos_qtty * sizeof(t_mutex));
	table->philos = malloc(table->philos_qtty * sizeof(t_philo));
}
