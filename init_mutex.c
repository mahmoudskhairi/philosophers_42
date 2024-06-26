/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:14:21 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/30 17:27:10 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	init_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->mutex = malloc(data->philos_nbr * sizeof(pthread_mutex_t));
	if (pthread_mutex_init(&data->print, NULL) != 0
		|| pthread_mutex_init(&data->death, NULL) != 0
		|| pthread_mutex_init(&data->meal_mutex, NULL) != 0)
	{
		destroy_mutex(data, philo);
		return (0);
	}
	while (i < data->philos_nbr)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0
			|| pthread_mutex_init(&philo[i].eat_mutex, NULL) != 0)
		{
			destroy_mutex(data, philo);
			return (0);
		}
		i++;
	}
	return (1);
}
