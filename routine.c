/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:40:57 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/05 15:38:15 by aoussama         ###   ########.fr       */
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
                print_status(philo,"has taken a fork");
            pthread_mutex_lock(philo->right_fork);
                print_status(philo,"has taken a fork");
        }
        else
        {
            pthread_mutex_lock(philo->right_fork);
                print_status(philo,"has taken a fork");
            pthread_mutex_lock(&philo->left_fork);
                print_status(philo,"has taken a fork");
        }
            print_status(philo,"is eating");
            ft_usleep(philo->info->eating);
            philo->nbr_eating++;
        pthread_mutex_unlock(&philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        print_status(philo,"is sleeping");
        ft_usleep(philo->info->sleeping);
        print_status(philo,"is thinking");
    }
}

void *monitor_thread(void *arg)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)arg;
    while (1)
    {
        i = 0;
        if (philo->info->nbr_eat != -1)
        {
            while (i < philo->info->philo)
            {
                if (philo[i].nbr_eating == philo->info->nbr_eat)
                {
                    philo[i].info->dead = 1;
                    return (NULL);
                }
                i++;
            }
            i = 0;
        }
        while (i < philo->info->philo)
        {
            if ((get_time_ms() - philo[i].last_eat) > (unsigned long)philo->info->die)
            {
                print_status(&philo[i],"died");
                philo[i].info->dead = 1;
                return (NULL);
            }
            i++;
        }
    }
    return (NULL);
}
