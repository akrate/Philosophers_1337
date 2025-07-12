/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:03:39 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/12 14:26:18 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi_use(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (checking_nbr(str) == 1)
	{
		return (-1);
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (result > 2147483647)
		{
			printf("number is long\n");
			return (-1);
		}
		i++;
	}
	return (result);
}

int	checking_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("please use only positive number without a sing :) \n");
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void	print_status(t_philo *philo, char *str, int i)
{
	pthread_mutex_lock(&philo->info->lock_print);
	pthread_mutex_lock(&philo->info->lock_dead);
	if (philo->info->dead == 0)
		printf("%ld %d %s\n", get_time_ms() - philo->info->start_time,
			philo->id, str);
	if (i == 1)
		philo->info->dead = 1;
	pthread_mutex_unlock(&philo->info->lock_dead);
	pthread_mutex_unlock(&philo->info->lock_print);
}

void	ft_usleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;

	start = get_time_ms();
	while (get_time_ms() - start < time)
	{
		pthread_mutex_lock(&philo->info->lock_dead);
		if (philo->info->dead != 0)
		{
			pthread_mutex_unlock(&philo->info->lock_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->info->lock_dead);
		if (get_time_ms() - start >= time)
			break ;
		usleep(50);
	}
}
