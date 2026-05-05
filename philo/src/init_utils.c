/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:04:19 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:26:52 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	create_philos(t_data *data)
{
	data->philos = malloc(data->philo_count * sizeof(t_philosopher));
	if (!data->philos)
		return (-1);
	return (0);
}

int	create_forks(t_data *data)
{
	data->forks = malloc(data->philo_count * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (-1);
	return (0);
}
