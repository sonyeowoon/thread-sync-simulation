/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:27:04 by sangseo           #+#    #+#             */
/*   Updated: 2025/06/05 03:25:04 by sangseo          ###   ########.fr       */
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

int	ft_atoi(char *s)
{
	int	n;
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
