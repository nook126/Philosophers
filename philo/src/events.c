/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:59:22 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:32:17 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_sim_state(t_data *data)
{
	pthread_mutex_lock(&data->access_mutex);
	if (data->death_flag == 1)
	{
		pthread_mutex_unlock(&data->access_mutex);
		return (1);
	}
	// if (data->sim_stopped == 1)// TODO: commented out
	// {
	// 	pthread_mutex_unlock(&data->access_mutex);
	// 	return (1);
	// }
	pthread_mutex_unlock(&data->access_mutex);
	return (0);
}

int	eat_event(t_data *data, t_philosopher *philo)
{
	if (takeforks_event(data, philo))
		return (1);
	if (check_sim_state(data))
		return (1);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_timestamp = time_stamp(data);
	philo->eat_count++;
	log_event(data, philo->id, EATING);
	pthread_mutex_unlock(&philo->meal_mutex);
	usleep(data->time_to_eat * 1000);
	returnforks_event(data, philo);
	return (0);
}

int	sleep_event(t_data *data, t_philosopher *philo)
{
	if (check_sim_state(data))
		return (1);
	log_event(data, philo->id, SLEEPING);
	usleep(data->time_to_sleep * 1000);
	return (0);
}

int	think_event(t_data *data, t_philosopher *philo)
{
	long	think_time;

	think_time = ((data->time_to_die - data->time_to_eat
		- data->time_to_sleep) / 2);
	if (check_sim_state(data))
		return (1);
	log_event(data, philo->id, THINKING);
	if (think_time < 0)
		think_time = 0;
	usleep(think_time * 1000);
	return (0);
}
