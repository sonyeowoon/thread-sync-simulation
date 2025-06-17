/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:52:59 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/18 05:23:53 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_arg_exit(void)
{
	printf("Invalid argument\n");
	return (0);
}

int	init_vars_error(void)
{
	printf("'init_vars()' failure!\nPlease check malloc in 'init_vars()'");
	return (0);
}

int	if_all_ate(int count, t_philo *philos)
{
	if (count >= philos->vars->args[0])
	{
		pthread_mutex_lock(&(philos->vars->ate_enough_mutex));
		philos->vars->all_ate_enough = 1;
		pthread_mutex_unlock(&(philos->vars->ate_enough_mutex));
		return (1);
	}
	return (0);
}
