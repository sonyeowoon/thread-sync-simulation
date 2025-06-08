/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:28:12 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/09 01:06:18 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_vars
{
	int	args[5];
	int	start_time;
	pthread_mutex_t	*fork;
	pthread_t	*threads;
}	t_vars;

int	ft_isdigit(int c);
long long	ft_atoi(char *s);
int	check_int(long long n);
int	get_ms_time(void);
int	invalid_arg_exit(void);

#endif
