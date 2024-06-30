/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:29:31 by ahyildir          #+#    #+#             */
/*   Updated: 2024/06/30 17:29:33 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		ft_error("Wrong amount of arguments!");
	if (parse_input(&table, av, ac))
		ft_error("An error occurred while parsing input!");
	if (start_simulation(&table))
		ft_error("An error occurred while starting simulation!");
	return (0);
}
