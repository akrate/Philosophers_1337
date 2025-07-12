/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:59:30 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/12 14:28:14 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_int(int ac, t_info test)
{
	if (test.eating == -1)
		return (1);
	if (test.philo == -1)
		return (1);
	if (test.philo == 0)
	{
		printf("number of philosofers is not correct ");
		printf("please use number bigger than 0\n");
		return (1);
	}
	if (test.sleeping == -1)
		return (1);
	if (test.die == -1)
		return (1);
	if (ac == 6)
	{
		if (test.nbr_eat == -1)
			return (1);
	}
	return (0);
}

void	ft_lock_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->lock_dead);
	philo->info->dead = 1;
	pthread_mutex_unlock(&philo->info->lock_dead);
}

void	mutex_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping_routine(t_philo *philo)
{
	print_status(philo, "is sleeping", 0);
	ft_usleep(philo->info->sleeping, philo);
}
