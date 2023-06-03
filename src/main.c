#include "header.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (set_args(argc, argv))
		return (1);
	set_table(&table, argc, argv);
	if (init_thread(&table))
		return (1);
	burn(&table);
	return (0);
}
