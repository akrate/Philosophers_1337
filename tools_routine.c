/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:28:29 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/12 14:25:28 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_lock_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo, "has taken a fork", 0);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork", 0);
}

void	mutex_lock_right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo, "has taken a fork", 0);
}

void	get_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_eat_last);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&philo->lock_eat_last);
}

int	ft_die(t_philo *philo)
{
	int	s;

	pthread_mutex_lock(&philo->info->lock_dead);
	s = philo->info->dead;
	pthread_mutex_unlock(&philo->info->lock_dead);
	return (s);
}
