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

void	init_vars(pthread_t **t, t_vars *vars)
{
	vars->start_time = get_ms_time();
	*t = (pthread_t *)malloc(sizeof(pthread_t) * (vars->args)[0]);
	vars->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (vars->args)[0]);
}

void	*philosopher_routine(void *vars)
{
	t_vars *v;
	v = (t_vars *)vars;
	printf("%d\n", v->n);
	sleep(1);
	printf("%d\n", v->n);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int	i;
	pthread_t	*t;

	if (ac < 5 || ac > 6)
		return (invalid_arg_exit());
	if (init_args(av, vars.args) == 0)
		return (invalid_arg_exit());
	init_vars(&t, &vars);
	i = 0;
	while (i < (vars.args)[0])
	{
		vars.n = i;
		pthread_create(&t[i], NULL, philosopher_routine, (t_vars *)&vars);
		i++;
	}
	while (i < (vars.args)[0])
	{
		pthread_join(t[i], NULL);
		i++;
	}
	printf("All philosophers are done.\n");
	return (0);
}
