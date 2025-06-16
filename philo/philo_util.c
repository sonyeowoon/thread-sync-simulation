/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:27:04 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/16 23:12:49 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long long	ft_atoi(char *s)
{
	long long	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		n = 10 * n + (s[i] - '0');
		i++;
	}
	return (n);
}

int	check_int(long long n)
{
	if (n != (int)n)
		return (0);
	return (1);
}

int	safe_print(t_philo *philos, char *msg)
{
	pthread_mutex_lock(&(philos->vars->print_mutex));
	if (is_exit(philos))
	{
		pthread_mutex_unlock(&(philos->vars->print_mutex));
		return (0);
	}
	printf("%d %d %s\n", philo_timestamp(philos), philos->index, msg);
	pthread_mutex_unlock(&(philos->vars->print_mutex));
	return (1);
}

int	philo_usleep(t_philo *philos, int us)
{
	int	n;
	int	i;

	n = us / 100;
	i = 0;
	while (i < n)
	{
		if (is_exit(philos) == 1)
			return (0);
		usleep(100);
		i++;
	}
	return (1);
}
