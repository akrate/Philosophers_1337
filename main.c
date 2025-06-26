/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:08 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/26 23:04:11 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"




int main(int ac,char **av)
{
    if (ac < 5 || ac > 6)
    {
        write (2,"error\n",6);
        return (1);
    }
    t_info info;

    info = init_struct(ac,av);
    printf("philo = %d\n",info.philo);
    printf("died = %d\n",info.died);
    printf("eating = %d\n",info.eating);
    printf("sleeping = %d\n",info.sleeping);
    printf("nbr_eat = %d\n",info.nbr_eat);
}