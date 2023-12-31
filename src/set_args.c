/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:44:53 by hbernard          #+#    #+#             */
/*   Updated: 2023/06/22 15:45:48 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_digits(char *argv);

int	set_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("FAIL: wrong number of arguments\n");
		return (1);
	}
	i = 0;
	while (++i < argc)
		if (check_digits(argv[i]))
			return (1);
	return (0);
}

int	check_digits(char *argv)
{
	int	i;

	if (ft_atoi(argv) <= 0)
	{
		printf("FAIL: The argument must be greater than zero\n");
		return (1);
	}
	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			printf("FAIL: The argument %s must only contain numbers.\n", argv);
			return (1);
		}
		i++;
	}
	return (0);
}
