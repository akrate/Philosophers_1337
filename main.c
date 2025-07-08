/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:08 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/08 11:58:45 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac,char **av)
{
    if (ac < 5 || ac > 6)
        return (write (2,"error\n",6),1);
    t_info info;
    t_philo *philosophers;
    pthread_t monitor;
    int i;

    i = 0;
    
    info = init_struct(ac,av);
    if (info.overflow == 1)
        return (1);
    philosophers = init_data(info);
    if (philosophers == NULL)
        return (1);
    init_info_and_link_philos(philosophers,&info);
    while (i < info.philo)
    {
        pthread_create(&philosophers[i].philo,NULL,&routine_philo,&philosophers[i]);
        i++;
    }
    pthread_create(&monitor,NULL,&monitor_thread,philosophers);
    i = 0;
    pthread_join(monitor,NULL);
    while (i < info.philo)
    {
        pthread_join(philosophers[i].philo,NULL);
        i++;
    }
    return (0);
}



