/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:40:57 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/04 16:04:27 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine_philo(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    philo->last_eat = get_time_ms();
    
    if (philo->id % 2 == 0)
        usleep(500);
    while (1)
    {
        if (philo->id % 2 != 0)
        {
            pthread_mutex_lock(&philo->left_fork);
                print_status(philo,"has taken a fork\n");
            pthread_mutex_lock(philo->right_fork);
                print_status(philo,"has taken a fork\n");
        }
        else
        {
            pthread_mutex_lock(philo->right_fork);
                print_status(philo,"has taken a fork\n");
            pthread_mutex_lock(&philo->left_fork);
                print_status(philo,"has taken a fork\n");
        }
            print_status(philo,"is eating\n");
            ft_usleep(philo->info->eating);
        pthread_mutex_unlock(&philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        print_status(philo,"is sleeping\n");
        ft_usleep(philo->info->sleeping);
        print_status(philo,"is thinking\n");
    }
}
