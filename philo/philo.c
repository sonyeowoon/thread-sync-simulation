/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:59:14 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/07 22:05:46 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(char **av, int *args)
{
	int	i;
	int	j;
	long long	n;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		n = ft_atoi(av[i]);
		if (check_int(n) == 0)
			return (0);
		*args = (int)n;
		args++;
		i++;
	}
	return (1);
}

void	*philosopher_routine(void *args)
{
}

int	main(int ac, char **av)
{
	int	args[5];
	int	i;
	int	start_time;
	pthread_t	t;

	if (ac < 5 || ac > 6)
		return (invalid_arg_exit());
	if (init_args(av, args) == 0)
		return (invalid_arg_exit());
	start_time = get_ms_time();
	i = 0;
	while (i < args[0])
	{
		pthread_create(&t, NULL, philosopher_routine, (int *)args);
		i++;
	}
}
