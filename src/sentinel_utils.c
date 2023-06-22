#include "header.h"

void	set_dead(t_table *t)
{
	t->has_dead = 1;
}

long	get_last_meal(t_philo *ph)
{
	long	l_meal;

	l_meal = ph->last_meal;
	return (l_meal);
}