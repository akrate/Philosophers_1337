/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:08 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/30 18:01:11 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac,char **av)
{
    if (ac < 5 || ac > 6)
        return (write (2,"error\n",6),1);
    t_info info;
    t_philo *philosophers;
    
    info = init_struct(ac,av);
    philosophers = init_data(info);
    if (philosophers == NULL)
        return (1);
    init_info_and_link_philos(philosophers,&info);
    
    
}

