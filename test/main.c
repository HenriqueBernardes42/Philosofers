#include <stdio.h>
#include <stdlib.h>

typedef struct s_table
{
    int qtty;
    struct s_philo **philo;
} t_table;

typedef struct s_philo
{
    int id;
    struct s_table *table;
} t_philo;

void create_table(t_table *table);


int main()
{
    t_table *table;
    t_philo **philo;
    int     i;

    table = malloc(sizeof(t_table));
    table->qtty = 5;
    philo = malloc(table->qtty * sizeof(*philo));
    i = 0;
    while(i < table->qtty)
    {
        philo[i] = malloc(sizeof(t_philo));
        philo[i]->id = i;
        ++i;
    }

    table->philo = philo;
    create_table(table);

    return 0;
}

void create_table(t_table *table)
{
    printf("philo id = %d\n", table->philo[3]->id);
}