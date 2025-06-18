/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 04:46:23 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/18 09:34:15 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork_reverse(t_philo *philos)
{
	pthread_mutex_lock(philos->fork2);
	if (safe_print(philos, "has taken a fork") == 0)
	{
		pthread_mutex_unlock(philos->fork2);
		return (0);
	}
	if (philos->vars->args[0] == 1)
	{
		pthread_mutex_unlock(philos->fork2);
		return (0);
	}
	pthread_mutex_lock(philos->fork1);
	if (safe_print(philos, "has taken a fork") == 0)
	{
		pthread_mutex_unlock(philos->fork2);
		pthread_mutex_unlock(philos->fork1);
		return (0);
	}
	return (1);
}

int	take_fork(t_philo *philos)
{
	if (philos->index % 2 == 0)
	{
//		printf("End philo fork : %d\n", get_ms_time());
		if (take_fork_reverse(philos) == 0)
			return (0);
	}
	else
	{
//		printf("%d philo fork : %d\n", philos->index, get_ms_time());
		pthread_mutex_lock(philos->fork1);
		if (safe_print(philos, "has taken a fork") == 0)
		{
			pthread_mutex_unlock(philos->fork1);
			return (0);
		}
		pthread_mutex_lock(philos->fork2);
		if (safe_print(philos, "has taken a fork") == 0)
		{
			pthread_mutex_unlock(philos->fork2);
			pthread_mutex_unlock(philos->fork1);
			return (0);
		}
	}
	return (1);
}

int	philo_eat(t_philo *philos)
{
	if (safe_print(philos, "is eating") == 0)
		return (0);
	pthread_mutex_lock(&(philos->vars->eat_mutex));
	if (is_exit(philos))
	{
		pthread_mutex_unlock(&(philos->vars->eat_mutex));
		return (0);
	}
	philos->last_eat_time = get_ms_time();
	philos->eat_count++;
	pthread_mutex_unlock(&(philos->vars->eat_mutex));
	if (philo_usleep(philos, philos->vars->args[2] * 1000) == 0)
		return (0);
	pthread_mutex_unlock(philos->fork2);
	pthread_mutex_unlock(philos->fork1);
	return (1);
}

int	philo_sleep(t_philo *philos)
{
	if (is_exit(philos) == 1)
		return (0);
	safe_print(philos, "is sleeping");
	if (philo_usleep(philos, philos->vars->args[3] * 1000) == 0)
		return (0);
	safe_print(philos, "is thinking");
	return (1);
}

int	is_exit(t_philo *philos)
{
	pthread_mutex_lock(&(philos->vars->dead_mutex));
	if (philos->vars->is_dead == 1)
	{
		pthread_mutex_unlock(&(philos->vars->dead_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philos->vars->dead_mutex));
	pthread_mutex_lock(&(philos->vars->ate_enough_mutex));
	if (philos->vars->all_ate_enough == 1)
	{
		pthread_mutex_unlock(&(philos->vars->ate_enough_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philos->vars->ate_enough_mutex));
	return (0);
}
