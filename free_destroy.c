/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:13:03 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/30 13:15:34 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	destroy_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->meal_mutex);
	while (i < data->philos_nbr)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		pthread_mutex_destroy(&philo[i].eat_mutex);
		i++;
	}
}

void	free_all(t_data *data, t_philo *philo)
{
	free(philo);
	philo = NULL;
	free(data->mutex);
	data->mutex = NULL;
}
