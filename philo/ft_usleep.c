/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:36:41 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/23 12:54:28 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	get_currect_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(int time_to_sleep, t_philo *philo)
{
	int	current_time;
	int	expected_time;

	current_time = get_currect_time();
	expected_time = current_time + time_to_sleep;
	while (get_currect_time() < expected_time)
	{
		if (get_death(philo))
			break ;
		usleep(200);
	}
}
