/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/12 14:27:20 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	int				philo;
	int				die;
	int				eating;
	int				sleeping;
	int				nbr_eat;
	int				overflow;
	unsigned long	start_time;
	int				dead;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_eat;

}					t_info;

typedef struct s_philo
{
	int				id;
	unsigned long	last_eat;
	int				nbr_eating;
	t_info			*info;
	pthread_t		*philo;
	pthread_mutex_t	lock_eat_last;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;

}					t_philo;

int					checking_nbr(char *str);
long				ft_atoi_use(char *str);
t_philo				*init_data(t_info *info);
void				init_info_and_link_philos(t_philo *philo, t_info *info);
t_info				init_struct(int ac, char **av);
unsigned long		get_time_ms(void);
void				ft_usleep(unsigned long time, t_philo *philo);
void				*routine_philo(void *arg);
void				print_status(t_philo *philo, char *str, int i);
int					check_int(int ac, t_info test);
void				*monitor_thread(void *arg);

void				get_last_eat(t_philo *philo);
void				mutex_unlock(t_philo *philo);
void				mutex_lock_right(t_philo *philo);
void				mutex_lock_left(t_philo *philo);

#endif