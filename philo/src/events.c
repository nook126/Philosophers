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

void	eat_event(t_data *data, t_philosopher *philo)
{
	if (data->philo_count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		log_event(data, philo->id, FORK_TAKEN);

		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	//Might need to add logic for left or right fork first to prevent deadlock!
	pthread_mutex_lock(philo->left_fork);
	log_event(data, philo->id, FORK_TAKEN);
	pthread_mutex_lock(philo->right_fork);
	log_event(data, philo->id, FORK_TAKEN);
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}


void	sleep_event(t_data *data, t_philosopher *philo)
{

}
