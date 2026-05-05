/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:25:05 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:21:44 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (pthread_join(data->monitor_thread, NULL) != 0)
		return (-1);
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->access_mutex);
	free(data->philos);
	free(data->forks);
	return (0);
}
