/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:03:09 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/16 06:08:07 by sangseo          ###   ########.fr       */
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
	if (philos->index == 1)
	{
		pthread_mutex_destroy(&(philos->vars->print_mutex));
		pthread_mutex_destroy(&(philos->vars->ate_enough_mutex));
		pthread_mutex_destroy(&(philos->vars->dead_mutex));
	}
	pthread_mutex_destroy(&(*(philos->fork1)));
}
