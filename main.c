/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:08 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/10 15:19:26 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void creat_thread(t_philo *philo,pthread_t *monitor)
{
    int i;

    i = 0;
    while (i < philo->info->philo)
    {
        pthread_create(philo[i].philo,NULL,&routine_philo,&philo[i]);
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
        pthread_join(*philo[i].philo,NULL);
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
        free(philo[i].philo);
        i++;
    }
    free(philo);
}
void *one_philo_routine(void *arg)
{
    t_info *info;
    unsigned long start;
    
    info = (t_info *)arg;
    info->start_time = get_time_ms();
    printf("%ld 1 has taken a fork\n",get_time_ms() - info->start_time);
      start = get_time_ms();
    while(get_time_ms() - start < (unsigned long)info->die)
        usleep(100);
    printf("%ld 1 is died\n",get_time_ms() - info->start_time);
    return (NULL);
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
    if (info.philo == 1)
    {
        pthread_t philo;
        
        pthread_create(&philo,NULL,&one_philo_routine,&info);
        pthread_join(philo,NULL);
        return (0);
    }
    philosophers = init_data(&info);
    if (philosophers == NULL)
        return (1);
    creat_thread(philosophers,&monitor);
    join_thread(philosophers,&monitor);
    destroy_all(philosophers);
    return (0);
}



