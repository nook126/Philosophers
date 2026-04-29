/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:59:22 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/29 14:21:22 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO: death check before each event.
//TODO: check if death has happend after lock to exit.
// Might need to add logic for left or right fork first to prevent deadlock!
// need to add logic for return in the takeforks_event function

int	eat_event(t_data *data, t_philosopher *philo)
{
	printf("DEBUG: entered eat_event\n");
	if (takeforks_event(data, philo))
	{
		printf("DEBUG: takeforks_event returned 1! in eat_event\n");
		returnforks_event(data, philo);
		return (1);
	}
	log_event(data, philo->id, EATING);
	usleep(data->time_to_eat * 1000);
	returnforks_event(data, philo);
	return (0);
}

int	sleep_event(t_data *data, t_philosopher *philo)
{
	log_event(data, philo->id, SLEEPING);
	usleep(data->time_to_sleep * 1000);
	return (0);
}

//TODO: add fill-in time to think to use up till death margin.
int	think_event(t_data *data, t_philosopher *philo)
{
	log_event(data, philo->id, THINKING);
	usleep(2 * 1000);
	return (0);
}
