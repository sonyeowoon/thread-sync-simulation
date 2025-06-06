/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:59:14 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/06 15:49:17 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(char **av, int *args)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Invalid argument\n");
				return (0);
			}
			j++;
		}
		*args = ft_atoi(av[i]);
		args++;
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	args[5];
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid argument\n");
		return (0);
	}
	if (init_args(av, args) == 0)
		return (0);
	//number_of_philos(args[1]);
	while (i < args[0])
	{
		printf("%s\n", *av);
		av++;
	}
}
