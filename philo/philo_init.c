/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:21:54 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/14 20:26:03 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(char **av, int *args)
{
	int			i;
	int			j;
	long long	n;

	args[4] = -1;
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

void	init_philos(t_vars *vars, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < vars->args[0])
	{
		(*philos)[i].index = i + 1;
		(*philos)[i].vars = *vars;
		pthread_mutex_init(&(vars->fork[i]), NULL);
		(*philos)[i].fork1 = &(vars->fork[i]);
		(*philos)[i].fork1_idx = i + 1;
		(*philos)[i].last_eat_time = 0;
		(*philos)[i].eat_count = 0;
		if (i < vars->args[0] - 1)
		{
			(*philos)[i].fork2 = &(vars->fork[i + 1]);
			(*philos)[i].fork2_idx = i + 2;
		}
		else
		{
			(*philos)[i].fork2 = &(vars->fork[0]);
			(*philos)[i].fork2_idx = 1;
		}
		i++;
	}
}

int	init_vars(t_vars *vars, t_philo **philos)
{
	pthread_mutex_init(&(vars->print_mutex), NULL);
	vars->start_time = get_ms_time();
	vars->life = vars->args[1];
	vars->all_ate_enough = 0;
	vars->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			(vars->args)[0]);
	if (vars->fork == 0)
		return (0);
	*philos = (t_philo *)malloc(sizeof(t_philo) * vars->args[0]);
	if (philos == 0)
	{
		free(vars->fork);
		return (0);
	}
	init_philos(vars, philos);
	return (1);
}
