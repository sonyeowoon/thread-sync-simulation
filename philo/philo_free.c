/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:03:09 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/16 19:56:59 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free(t_vars *vars, t_philo **philos)
{
	free((*vars).fork);
	free(*philos);
}

void	all_mutex_destroy(t_philo *philos)
{
	int	i;
	int	max;

	pthread_mutex_destroy(&(philos->vars->print_mutex));
	pthread_mutex_destroy(&(philos->vars->ate_enough_mutex));
	pthread_mutex_destroy(&(philos->vars->dead_mutex));
	pthread_mutex_destroy(&(philos->vars->eat_mutex));
	i = 0;
	max = philos->vars->args[0];
	while (i < max)
	{
		pthread_mutex_destroy(&(philos->vars->fork[i]));
		i++;
	}
}
