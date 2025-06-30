/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:54:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/30 18:00:15 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info init_struct(int ac,char **av)
{
    t_info info;

    info.philo = ft_atoi_use(av[1]);
    info.die = ft_atoi_use(av[2]);
    info.eating = ft_atoi_use(av[3]);
    info.sleeping = ft_atoi_use(av[4]);
    if (ac == 6)
        info.nbr_eat = ft_atoi_use(av[5]);
    else
        info.nbr_eat = -1;
    return (info);
}

t_philo *init_data(t_info info)
{
    t_philo *philo;
    int i;

    philo = malloc(sizeof(t_philo) * info.philo);
    if (philo ==  NULL)
        return (NULL);
    i = 0;
    while(i < info.philo)
    {
        philo[i].id = i + 1;
        pthread_mutex_init(&philo[i].left_fork,NULL);
        i++;
    }
    i = 0;
    while (i < info.philo)
    {
        philo[i].right_fork = &philo[(i + 1) % info.philo].left_fork;
        i++;
    }
    return (philo);
}

void init_info_and_link_philos(t_philo *philo,t_info *info)
{
    int i;
    
    i = 0;
    pthread_mutex_init(&info->lock_dead,NULL);
    pthread_mutex_init(&info->lock_print,NULL);

    while (i < info->philo)
    {
        philo[i].info = info;
        i++;
    }
}