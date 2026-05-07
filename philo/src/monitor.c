/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:00:13 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:30:39 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data, size_t i)
{
	pthread_mutex_lock(&data->philos[i].meal_mutex);
	if (time_stamp(data) > (data->philos[i].last_meal_timestamp
			+ (long)data->time_to_die))
	{
		pthread_mutex_lock(&data->access_mutex);
		data->death_flag = 1;
		log_event(data, data->philos[i].id, DIED);
		pthread_mutex_unlock(&data->access_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	return (0);
}

int	check_stopped(t_data *data, size_t i)
{
	if (data->philos[i].eat_count == data->must_eat_count
		&& (data->philos[i].eat_count != 0))
	{
		pthread_mutex_lock(&data->access_mutex);
		data->sim_stopped = 1;
		pthread_mutex_unlock(&data->access_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_thread(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (check_death(data, i))
				return (NULL);
			// if (check_stopped(data, i))// TODO: commented out
			// 	return (NULL);
			i++;
		}
	}
	return (NULL);
}
