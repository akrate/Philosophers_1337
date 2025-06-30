/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:03:39 by aoussama          #+#    #+#             */
/*   Updated: 2025/06/30 17:18:19 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi_use(char *str)
{
	int	i;
	long	result;

    checking_nbr(str);
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
            exit (1);
        }
		i++;
	}
	return (result);
}
void checking_nbr(char *str)
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