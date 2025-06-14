/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:59:14 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/14 20:48:03 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	while (1)
	{
		if (philo_eat(p) == 0)
		{
			all_mutex_destroy(p);
			return (0);
		}
		if (philo_sleep(p) == 0)
		{
			all_mutex_destroy(p);
			return (0);
		}
	}
	all_mutex_destroy(p);
	return (0);
}

void	*check_all_ate(void *philos)
{
	int	i;
	int	count;
	t_philo *p;

	p = (t_philo *)philos;
	if (p->vars.args[4] < 0)
		return (0);
	i = 0;
	count = 0;
	while (1)
	{
		if (p[i].eat_count >= p->vars.args[4])
			count++;
		else
			count = 0;
		if (count >= p->vars.args[0])
		{
			p->vars.all_ate_enough = 1;
			return (0);
		}
		i++;
		if (i == p->vars.args[0])
			i = 0;
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philos;
	int		i;
	pthread_t	ate_check_thread;

	if (ac < 5 || ac > 6)
		return (invalid_arg_exit());
	if (init_args(av, vars.args) == 0)
		return (invalid_arg_exit());
	if (init_vars(&vars, &philos) == 0)
		return (init_vars_error());
	pthread_create(&ate_check_thread, NULL, check_all_ate, philos);
	i = 0;
	while (i < (vars.args)[0])
	{
		pthread_create(&(philos[i].thread), NULL, philosopher_routine, &(philos[i]));
		i++;
	}
	i = 0;
	while (i < (vars.args)[0])
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(ate_check_thread, NULL);
	printf("All philosophers are done.\n");
	philo_free(&vars, &philos);
	return (0);
}
