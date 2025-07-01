/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/01 14:50:35 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_info
{
    int eating;
    int sleeping;
    int nbr_eat;
    int die;
    int philo;
    unsigned long start_time; // BACH N9DR NHSB W9T.
    int dead; // FALG BACH N3RF BLI CHI PHILO MAT.
    pthread_mutex_t lock_print; //BACH NPRINTI BLAMA IW93 LIYA MOCHKIL.
    pthread_mutex_t lock_dead; // BACH MCHOF WACH MAT LIYA CHI PHILO BLAMA IW93 CHIMOCHKIL.
} t_info;

typedef struct s_philo
{
    int id;
    unsigned long last_eat;
    t_info *info;
    pthread_t philo;
    pthread_mutex_t left_fork;
    pthread_mutex_t *right_fork;
    
} t_philo;
// typedef struct s_data
// {
//     int id;
//     int *die_philo;
//     pthread_t philo;
//     t_info info;
//     size_t time_start;
//     size_t time_up;
//     pthread_mutex_t *forks;
// } t_data;


void checking_nbr(char *str);
long	ft_atoi_use(char *str);
t_info init_struct(int ac,char **av);
void checking_nbr(char *str);
long	ft_atoi_use(char *str);
t_philo *init_data(t_info info);
void init_info_and_link_philos(t_philo *philo,t_info *info);
unsigned long get_time_ms();

#endif