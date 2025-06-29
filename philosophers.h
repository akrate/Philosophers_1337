/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/29 14:28:37 by aoussama         ###   ########.fr       */
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
    int die;
    int philo;
} t_info;

typedef struct s_data
{
    int id;
    int *die_philo;
    pthread_t philo;
    t_info info;
    size_t time_start;
    size_t time_up;
    pthread_mutex_t *forks;
} t_data;

typedef struct s_philo
{
    int id;
    int last_eat;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    
} t_philo;

void checking_nbr(char *str);
long	ft_atoi_use(char *str);
t_info init_struct(int ac,char **av);
void checking_nbr(char *str);
long	ft_atoi_use(char *str);

#endif