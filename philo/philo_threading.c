/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:49:45 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/16 19:57:53 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_all_ate(void *philos)
{
	int	i;
	int	count;
	t_philo *p;

	p = (t_philo *)philos;
	if (p->vars->args[4] < 0)
		return (0);
	i = 0;
	count = 0;
	while (is_exit(p) == 0)
	{
		if (p->vars->is_dead)
			return (0);
		if (p[i].eat_count >= p->vars->args[4])
			count++;
		else
			count = 0;
		if (count >= p->vars->args[0])
		{
			pthread_mutex_lock(&(p->vars->ate_enough_mutex));
			p->vars->all_ate_enough = 1;
			pthread_mutex_unlock(&(p->vars->ate_enough_mutex));
			return (0);
		}
		i++;
		if (i == p->vars->args[0])
			i = 0;
		usleep(50);
	}
	return (0);
}

void	*philosopher_routine(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	if (p->vars->args[0] == 1)
	{
		usleep(p->vars->args[1] * 1000);
		safe_print(philos, "died");
		return (0);
	}
	if ((p->vars->args[0] % 2) && p->index == p->vars->args[0])
		usleep(100);
	if (p->index % 2 == 0)
		usleep(200);
	while (1)
	{
		if (is_exit(p))
			return (0);
		if (philo_eat(p) == 0)
			return (0);
		if (philo_sleep(p) == 0)
			return (0);
		usleep(50);
	}
	all_mutex_destroy(p);
	return (0);
}

void	*philos_monitoring(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	while (is_exit(philos) == 0)
	{
		if (get_remaining_life(philos) <= 0)
		{
			pthread_mutex_lock(&(p->vars->dead_mutex));
			p->vars->is_dead = 1;
			pthread_mutex_unlock(&(p->vars->dead_mutex));
			pthread_mutex_lock(&(p->vars->print_mutex));
			if (p->vars->all_ate_enough == 1)
				return (0);
			printf("%d %d died\n", philo_timestamp(p), p->index);
			pthread_mutex_unlock(&(p->vars->print_mutex));
		}
		usleep(50);
	}
	return (0);
}

void	philo_threading(t_philo *philos, t_vars *vars)
{
	pthread_t	ate_check_thread;
	pthread_t	*monitoring_thread;
	int	i;

	pthread_create(&ate_check_thread, NULL, check_all_ate, philos);
	monitoring_thread = (pthread_t *)malloc(sizeof(pthread_t) * vars->args[0]);
	if (monitoring_thread == 0)
		return ;
	i = 0;
	while (i < vars->args[0])
	{
		pthread_create(&(monitoring_thread[i]), NULL, philos_monitoring, &(philos[i]));
		pthread_create(&(philos[i].thread), NULL, philosopher_routine, &(philos[i]));
		i++;
	}
	i = 0;
	while (i < vars->args[0])
	{
		pthread_join(philos[i].thread, NULL);
		pthread_join(monitoring_thread[i], NULL);
		i++;
	}
	all_mutex_destroy(philos);
	free(monitoring_thread);
	pthread_join(ate_check_thread, NULL);
}
