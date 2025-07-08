/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:08 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/08 20:04:39 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void creat_thread(t_philo *philo,pthread_t *monitor)
{
    int i;

    i = 0;
    while (i < philo->info->philo)
    {
        pthread_create(&philo[i].philo,NULL,&routine_philo,&philo[i]);
        i++;
    }
    pthread_create(monitor,NULL,&monitor_thread,philo);
}
void join_thread(t_philo *philo,pthread_t *monitor)
{
    int i;

    i = 0;
    pthread_join(*monitor,NULL);
    while (i < philo->info->philo)
    {
        pthread_join(philo[i].philo,NULL);
        i++;
    }
}
void destroy_all(t_philo *philo)
{
    int i;
    
    pthread_mutex_destroy(&philo->info->lock_print);
    pthread_mutex_destroy(&philo->info->lock_dead);
    pthread_mutex_destroy(&philo->info->lock_eat);
    i = 0;
    while (i < philo->info->philo)
    {
        pthread_mutex_destroy(&philo[i].left_fork);
        pthread_mutex_destroy(&philo[i].lock_eat_last);
        i++;
    }
    free(philo);
}
int main(int ac,char **av)
{
    if (ac < 5 || ac > 6)
        return (write (2,"error\n",6),1);
    t_info info;
    t_philo *philosophers;
    pthread_t monitor;

    info = init_struct(ac,av);
    if (info.overflow == 1)
        return (1);
    philosophers = init_data(&info);
    if (philosophers == NULL)
        return (1);
    creat_thread(philosophers,&monitor);
    join_thread(philosophers,&monitor);
    destroy_all(philosophers);
    return (0);
}



