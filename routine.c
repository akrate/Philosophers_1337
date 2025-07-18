/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:40:57 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/18 09:18:23 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_routine(t_philo *philo)
{
	get_last_eat(philo);
	print_status(philo, "is eating", 0);
	ft_usleep(philo->info->eating, philo);
	pthread_mutex_lock(&philo->lock_count_eat);
	philo->nbr_eating++;
	pthread_mutex_unlock(&philo->lock_count_eat);
}

void	thinking_routine(t_philo *philo)
{
	int	thinking_time;

	print_status(philo, "is thinking", 0);
	thinking_time = philo->info->die - (philo->info->eating
			+ philo->info->sleeping);
	if (thinking_time > 60)
		ft_usleep((unsigned long)thinking_time - 10, philo);
}

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->lock_eat_last);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&philo->lock_eat_last);
	if (philo->id % 2 != 0)
			usleep(50);
	while (!ft_die(philo))
	{
		if (philo->id % 2 == 0)
			mutex_lock_left(philo);
		else
		{
			mutex_lock_right(philo);
		}
		eat_routine(philo);
		if (ft_die(philo) == 1)
			return (mutex_unlock(philo), NULL);
		mutex_unlock(philo);
		sleeping_routine(philo);
		thinking_routine(philo);
	}
	return (NULL);
}

int	monitor_helper(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (philo->info->nbr_eat == -1)
		return (0);
	while (i < philo->info->philo)
	{
		pthread_mutex_lock(&philo[i].lock_count_eat);
		if (philo[i].nbr_eating >= philo->info->nbr_eat)
			count++;
		pthread_mutex_unlock(&philo[i].lock_count_eat);
		i++;
	}
	if (count >= philo->info->philo)
		return (1);
	return (0);
}

void	*monitor_thread(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	usleep(20 * (philo->info->philo / 2));
	while (1)
	{
		i = 0;
		while (i < philo->info->philo)
		{
			pthread_mutex_lock(&philo[i].lock_eat_last);
			if ((get_time_ms()
					- philo[i].last_eat) >= (unsigned long)philo->info->die)
			{
				print_status(&philo[i], "died", 1);
				return (pthread_mutex_unlock(&philo[i].lock_eat_last), NULL);
			}
			pthread_mutex_unlock(&philo[i].lock_eat_last);
			i++;
		}
		if (monitor_helper(philo))
			return (ft_lock_dead(philo), NULL);
		usleep(50);
	}
	return (NULL);
}
