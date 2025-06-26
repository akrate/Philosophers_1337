/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/26 23:04:50 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
 #include <pthread.h>

typedef struct s_info
{
    int eating;
    int sleeping;
    int nbr_eat;
    int died;
    int philo;
} t_info;
typedef struct s_data
{
    int id;
    int fork_left;
    int fork_right;
    pthread_t *philo;
} t_data;

void checking_nbr(char *str);
long	ft_atoi(char *str);
t_info init_struct(int ac,char **av);
void checking_nbr(char *str);
long	ft_atoi_use(char *str);

#endif