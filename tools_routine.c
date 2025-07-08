/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:28:29 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/08 19:55:30 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void mutex_lock_left(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork);
    print_status(philo,"has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    print_status(philo,"has taken a fork");
}
void mutex_lock_right(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_status(philo,"has taken a fork");
    pthread_mutex_lock(&philo->left_fork);
    print_status(philo,"has taken a fork");
}
void mutex_unlock(t_philo *philo)
{
    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void get_last_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock_eat_last);
        philo->last_eat = get_time_ms();
    pthread_mutex_unlock(&philo->lock_eat_last);
}