/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/05 15:35:55 by aoussama         ###   ########.fr       */
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
    int philo; //nbr fhilo
    int die; // w9t ila mklach fih khaso imout 
    int eating; // w9t li khas ib9a iyakol fih
    int sleeping; // w9t li khaso in3s fih
    int nbr_eat; // nbr ta3 chehal mn mra khaso iyakol
    int overflow; // hada drto 3la hsab overflow fi atoi
    unsigned long start_time; // BACH N9DR NHSB W9T.
    int dead; // FALG BACH N3RF BLI CHI PHILO MAT.
    pthread_mutex_t lock_print; //BACH NPRINTI BLAMA IW93 LIYA MOCHKIL.
    pthread_mutex_t lock_dead; // BACH MCHOF WACH MAT LIYA CHI PHILO BLAMA IW93 CHIMOCHKIL.
} t_info;

typedef struct s_philo
{
    int id; // hada id ta3 filo
    unsigned long last_eat; // w9t ta3 akhir mra kla fiha
    int nbr_eating;
    t_info *info;
    pthread_t philo;
    pthread_mutex_t left_fork; 
    pthread_mutex_t *right_fork;
    
} t_philo;


int checking_nbr(char *str);
long	ft_atoi_use(char *str);
t_philo *init_data(t_info info);
void init_info_and_link_philos(t_philo *philo,t_info *info);
t_info init_struct(int ac,char **av);
unsigned long get_time_ms();
void ft_usleep(unsigned long time);
void *routine_philo(void *arg);
void print_status(t_philo *philo,char *str);
int check_int(int ac,t_info test);
void *monitor_thread(void *arg);

#endif
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