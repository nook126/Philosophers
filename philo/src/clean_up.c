/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:25:05 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/29 14:02:48 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO:: commented out pthread_join for philo_threads since i will be using pthread_detach during the init faze.
//and using pthread_join for monitor_thread.
int	cleanup_data(t_data *data)
{
	size_t	i;

	if (!data->philos || !data->forks)
		return (-1);
	free(data->philos);
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		// if (pthread_join(data->philos[i].thread, NULL) != 0)
		// 	return (-1);
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	if (pthread_join(data->monitor_thread, NULL) != 0)
		return (-1);
	return (0);
}
