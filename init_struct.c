/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:54:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/27 21:10:10 by aoussama         ###   ########.fr       */
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
void init_data2(t_data *data)
{
    
}
t_data init_data(t_info info)
{
    t_data *philo;
    int i;

    philo = malloc(sizeof(t_data) * info.philo);
    i = 0;
    while(i < info.philo)
    {
        philo[i].id = i + 1;
        
    }
}