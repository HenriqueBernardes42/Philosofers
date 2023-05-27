#include "header.h"

static void set_mutex(t_table *table);
static void lock_mutexs(t_philo *philo);

void set_philo(t_table *table)
{
    int i;
    set_mutex(table);

    i = -1;
    while(++i < table->philo_qtty)
    {
        table->philos[i].id = i;
        table->philos[i].meals = 0;
        table->philos[i].last_meal = current_time();
        table->philos[i].l_fork = &table->forks[i];
        table->philos[i].r_fork = &table->forks[(i + 1) % table->philo_qtty];
        table->philos[i].table = table;
        lock_mutexs(&table->philos[i]);
    }
}

static void set_mutex(t_table *table)
{
    int i;

    i = -1;
    while(++i < table->philo_qtty)
        pthread_mutex_init(table->forks, NULL);
}

static void lock_mutexs(t_philo *philo)
{
    pthread_mutex_init(&philo->lock, NULL);
    pthread_mutex_init(&philo->meal, NULL);
}