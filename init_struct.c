/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:54:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/26 23:05:13 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info init_struct(int ac,char **av)
{
    t_info info;

    info.philo = ft_atoi_use(av[1]);
    info.died = ft_atoi_use(av[2]);
    info.eating = ft_atoi_use(av[3]);
    info.sleeping = ft_atoi_use(av[4]);
    if (ac == 6)
        info.nbr_eat = ft_atoi_use(av[5]);
    else
        info.nbr_eat = -1;
    return (info);
}