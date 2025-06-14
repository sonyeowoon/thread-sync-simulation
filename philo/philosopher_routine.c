/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 04:46:23 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/14 19:58:27 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->fork1);
	pthread_mutex_lock(philos->fork2);
	if (is_exit(philos) == 1)
	{
		pthread_mutex_unlock(philos->fork1);
		pthread_mutex_unlock(philos->fork2);
		return (0);
	}
	philos->last_eat_time = get_ms_time();
	philos->eat_count++;
	safe_print(philos, "has taken a fork");
	safe_print(philos, "is eating");
	usleep(philos->vars.args[2] * 1000);
	pthread_mutex_unlock(philos->fork1);
	pthread_mutex_unlock(philos->fork2);
	return (1);
}

int	philo_sleep(t_philo *philos)
{
	if (is_exit(philos) == 1)
		return (0);
	safe_print(philos, "is sleeping");
	usleep(philos->vars.args[3] * 1000);
	if (is_exit(philos) == 1)
		return (0);
	safe_print(philos, "is thinking");
	return (1);
}

int	is_exit(t_philo *philos)
{
	if (get_remaining_life(philos) <= 0)
	{
		safe_print(philos, "died");
		return (1);
	}
	if (philos->vars.all_ate_enough == 1)
		return (1);
	return (0);
}
