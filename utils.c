/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:59:30 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/04 15:15:05 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_int(int ac,t_info test)
{
    if (test.eating == -1)
        return (1);
    if (test.philo == -1)
        return (1);
    if (test.sleeping == -1)
        return (1);
    if (test.die == -1)
        return (1);
    if (ac == 6)
    {
        if (test.nbr_eat == -1)
            return (1);
    }
    return (0);
}