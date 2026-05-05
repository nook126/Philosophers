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
//FIX: alloced data gets freed while monitor_thread is still running, causing monitor_thread to access garbage data.
//Need to either have monitor_thread rejoin and make mainthread wait. or add a flag to make monitor_thread stop as
//soon as all threads have rejoined.
int	cleanup_data(t_data *data)
{
	size_t	i;

	if (!data->philos || !data->forks)
		return (-1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
  // if (pthread_join(data->monitor_thread, NULL) != 0)
  //   return (-1);//dont need to join since monitor_thread runs detached.
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free(data->philos);
  free(data->forks);
	return (0);
}
