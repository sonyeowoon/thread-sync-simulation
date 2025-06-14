/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:43:33 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/14 18:15:54 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

int	philo_timestamp(t_philo *philos)
{
	return (get_ms_time() - philos->vars.start_time);
}

int	get_remaining_life(t_philo *philos)
{
	return (philos->vars.life - (get_ms_time() - philos->last_eat_time));
}
