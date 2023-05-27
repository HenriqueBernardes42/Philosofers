#include "header.h"

void set_dinner(t_table *table)
{
    set_philo(table);
    printf("%ld time", table->philos->last_meal);
}