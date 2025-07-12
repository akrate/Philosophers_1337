/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:54:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/12 14:22:49 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	init_struct(int ac, char **av)
{
	t_info	info;

	info.philo = ft_atoi_use(av[1]);
	info.die = ft_atoi_use(av[2]);
	info.eating = ft_atoi_use(av[3]);
	info.sleeping = ft_atoi_use(av[4]);
	info.dead = 0;
	if (ac == 6)
		info.nbr_eat = ft_atoi_use(av[5]);
	else
		info.nbr_eat = -1;
	if (check_int(ac, info) == 1)
		info.overflow = 1;
	else
		info.overflow = 0;
	return (info);
}

t_philo	*init_data(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * info->philo);
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < info->philo)
	{
		philo[i].id = i + 1;
		philo[i].philo = malloc(sizeof(pthread_t));
		pthread_mutex_init(&philo[i].left_fork, NULL);
		i++;
	}
	i = 0;
	while (i < info->philo)
	{
		philo[i].right_fork = &philo[(i + 1) % info->philo].left_fork;
		i++;
	}
	if (philo != NULL)
		init_info_and_link_philos(philo, info);
	return (philo);
}

void	init_info_and_link_philos(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->lock_dead, NULL);
	pthread_mutex_init(&info->lock_print, NULL);
	pthread_mutex_init(&info->lock_eat, NULL);
	info->start_time = get_time_ms();
	while (i < info->philo)
	{
		philo[i].info = info;
		philo[i].nbr_eating = 0;
		pthread_mutex_init(&philo[i].lock_eat_last, NULL);
		i++;
	}
}
