/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:28:12 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/18 05:20:41 by sangseo          ###   ########.fr       */
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

typedef struct s_vars
{
	int				args[5];
	int				start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ate_enough_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	eat_mutex;
	int				life;
	int				all_ate_enough;
	int				is_dead;
}	t_vars;

typedef struct s_philo
{
	pthread_t		thread;
	int				index;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	int				fork1_idx;
	int				fork2_idx;
	t_vars			*vars;
	int				last_eat_time;
	int				eat_count;
}	t_philo;

int			init_args(char **av, int *args);
int			ft_isdigit(int c);
long long	ft_atoi(char *s);
int			check_int(long long n);
int			get_ms_time(void);
int			invalid_arg_exit(void);
int			init_vars_error(void);
void		philo_free(t_vars *vars, t_philo **philos);
int			init_vars(t_vars *vars, t_philo **philos);
int			philo_timestamp(t_philo *philos);
int			safe_print(t_philo *philos, char *msg);
int			philo_eat(t_philo *philos);
int			philo_sleep(t_philo *philos);
int			get_remaining_life(t_philo *philos);
int			is_exit(t_philo *philos);
void		all_mutex_destroy(t_philo *philos);
void		philo_threading(t_philo *philos, t_vars *vars);
int			philo_usleep(t_philo *philos, int us);
int			take_fork(t_philo *philos);
int			if_all_ate(int count, t_philo *philos);

#endif
