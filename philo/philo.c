/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:59:14 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/18 13:18:03 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philos;

	if (ac < 5 || ac > 6)
		return (invalid_arg_exit());
	if (init_args(av, vars.args) == 0)
		return (invalid_arg_exit());
	if (vars.args[0] == 0)
		return (invalid_arg_exit());
	if (init_vars(&vars, &philos) == 0)
		return (init_vars_error());
	philo_threading(philos, &vars);
	philo_free(&vars, &philos);
	return (0);
}
