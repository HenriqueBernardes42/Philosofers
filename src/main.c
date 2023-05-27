#include "header.h"

int main(int argc, char** argv)
{
    t_table table;

    if(!set_init_args(argc, argv, &table))
        return (ERR);
    set_dinner(&table);
    return (OK);
}