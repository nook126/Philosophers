/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:59:22 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/24 15:44:02 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO: death check before each event.
//TODO: check if death has happend after lock to exit.
// Might need to add logic for left or right fork first to prevent deadlock!

int	takeforks_event(t_data *data, t_philosopher *philo)
{
	if (data->philo_count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		log_event(data, philo->id, FORK_TAKEN);
		return (0);
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		log_event(data, philo->id, FORK_TAKEN);
		pthread_mutex_lock(philo->right_fork);
		log_event(data, philo->id, FORK_TAKEN);
		return (0);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		log_event(data, philo->id, FORK_TAKEN);
		pthread_mutex_lock(philo->left_fork);
		log_event(data, philo->id, FORK_TAKEN);
	}
	return (0);
}

int	returnforks_event(t_data *data, t_philosopher *philo)
{
	if (data->philo_count == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	return (0);
}

int	eat_event(t_data *data, t_philosopher *philo)
{
	log_event(data, philo->id, EATING);
	usleep(data->time_to_eat * 1000);
	return (0);
}

int	sleep_event(t_data *data, t_philosopher *philo)
{
	log_event(data, philo->id, SLEEPING);
	usleep(data->time_to_sleep * 1000);
	return (0);
}

//TODO: add fillin time to think if has time till death to use.
int	think_event(t_data *data, t_philosopher *philo)
{
	log_event(data, philo->id, THINKING);
	return (0);
}
