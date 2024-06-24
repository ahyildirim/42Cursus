#include "philosophers.h"

int main(int ac, char **av)
{
	t_table	table;

	if(ac != 5 && ac != 6)
		ft_error_msg("Wrong amount of inputs, try again.");
	if(parse_input(&table, av, ac))
		ft_error_msg("An error occured during parsing input, try again.");
	if(start_simulation(&table))
		ft_error_msg("An error occured during simulation, try again.");
	return (0);
}
