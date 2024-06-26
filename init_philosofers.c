/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosofers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:34:58 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/30 13:18:21 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	init_philosofers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		philo[i].data = data;
		philo[i].data->count_meals = 0;
		philo[i].index_philo = i + 1;
		philo[i].right_fork = &data->mutex[i];
		if (i == data->philos_nbr - 1)
			philo[i].left_fork = &data->mutex[0];
		else
			philo[i].left_fork = &data->mutex[i + 1];
		i++;
	}
}
