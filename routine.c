/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:40:57 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/06 20:38:21 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_die(t_philo *philo)
{
    int s;
    pthread_mutex_lock(&philo->info->lock_dead);
    s = philo->info->dead;
    pthread_mutex_unlock(&philo->info->lock_dead);
    return s;
}
void *routine_philo(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    philo->last_eat = get_time_ms();
    if (philo->id % 2 == 0)
        usleep(500);
    while (!ft_die(philo))
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
        pthread_mutex_lock(&philo->lock_eat_last);
        philo->last_eat = get_time_ms();
        pthread_mutex_unlock(&philo->lock_eat_last);
        ft_usleep(philo->info->eating);
        // usleep(philo->info->eating * 1000);
        philo->nbr_eating++;
        if (ft_die(philo) == 1)
        {
            pthread_mutex_unlock(&philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
            return (NULL);
        }
        pthread_mutex_unlock(&philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        print_status(philo,"is sleeping");
        ft_usleep(philo->info->sleeping);
        // usleep(philo->info->sleeping * 1000);
        print_status(philo,"is thinking");
        usleep(100);
    }
    return (NULL);
}
int monitor_helper(t_philo *philo)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    if (philo->info->nbr_eat == -1)
        return (0);
    while (i < philo->info->philo)
    {
        if (philo[i].nbr_eating == philo->info->nbr_eat)
            count++;
        i++;
    }
    if (count >= philo->info->philo)
        return (1);
    return (0);
}
void *monitor_thread(void *arg)
{
    t_philo *philo;
    int i;
    unsigned long last = 0;
    philo = (t_philo *)arg;
    usleep(1000);
    while (1)
    {
        i = 0;
        if (monitor_helper(philo) == 1)
        {
            pthread_mutex_lock(&philo->info->lock_eat);
                philo->info->dead = 1;
            pthread_mutex_unlock(&philo->info->lock_eat);
            return (NULL);
        }
        while (i < philo->info->philo)
        {
            pthread_mutex_lock(&philo->lock_eat_last);
                last = philo[i].last_eat;
                if ((get_time_ms() - last) >= (unsigned long)philo->info->die)
                {
                    print_status(&philo[i],"died");
                    pthread_mutex_lock(&philo->info->lock_eat);
                    philo[i].info->dead = 1;
                    pthread_mutex_unlock(&philo->info->lock_eat);
                    return (NULL);
                }
            pthread_mutex_unlock(&philo->lock_eat_last);
            i++;
        }
        usleep(500);
    }
    return (NULL);
}
  // if (philo->info->nbr_eat != -1)
        // {
            //     while (i < philo->info->philo)
            //     {
                //         if (philo[i].nbr_eating == philo->info->nbr_eat)
                //         {
                    //             philo[i].info->dead = 1;
                    //             return (NULL);
                    //         }
                    //         i++;
                    //     }
                    //     i = 0;
                    
        // }