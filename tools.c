/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:03:39 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/04 15:15:21 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi_use(char *str)
{
	int	i;
	long	result;

    if (checking_nbr(str) == 1)
        return (-1);
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
        if (result > 2147483647)
        {
            printf("nbr is long\n");
            return (-1);
        }
		i++;
	}
	return (result);
}
int checking_nbr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            write (2,"this number is not correct\n",27);
            return (1);
        }
        i++;
    }
    return (0);
}
unsigned long get_time_ms()
{
    struct timeval tv;
    
    gettimeofday(&tv,NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // had return ky 3tina w9t b millisecond ==> kt3ni parti mn taniya.
}

void print_status(t_philo *philo,char *str)
{
    pthread_mutex_lock(&philo->info->lock_print);
        printf("%ld %d %s\n",get_time_ms() - philo->info->start_time,philo->id,str);
    pthread_mutex_unlock(&philo->info->lock_print);
}
void ft_usleep(unsigned long time)
{
    unsigned long start;
    
    start = get_time_ms();
    while(get_time_ms() - start < time)
    {
        usleep(100);
    }
}