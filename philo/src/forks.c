/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:00:35 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/29 13:28:32 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_first(t_data *data, t_philosopher *philo)
{
  pthread_mutex_lock(philo->left_fork);
  if (check_death(data))
  {
    pthread_mutex_unlock(philo->left_fork);
    return (1);
  }
  log_event(data, philo->id, FORK_TAKEN);
  if (data->philo_count == 1)
    return (0);
  pthread_mutex_lock(philo->right_fork);
  if (check_death(data))
  {
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    return (1);
  }
  log_event(data, philo->id, FORK_TAKEN);
  return (0);
}

int	take_right_first(t_data *data, t_philosopher *philo)
{
  pthread_mutex_lock(philo->right_fork);
  if (check_death(data))
  {
    pthread_mutex_unlock(philo->right_fork);
    return (1);
  }
  log_event(data, philo->id, FORK_TAKEN);
  pthread_mutex_lock(philo->left_fork);
  if (check_death(data))
  {
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    return (1);
  }
  log_event(data, philo->id, FORK_TAKEN);
  return (0);
}

// TODO: move fork takes to seperate functions left_first & right_first.
int	takeforks_event(t_data *data, t_philosopher *philo)
{
	if (data->philo_count == 1)
	{
    if (take_left_first(data, philo))
		  return (1);
		return (0);
	}
	else if (philo->id % 2 == 0)
	{
    if (take_left_first(data, philo))
		  return (1);
	}
	else
	{
    if (take_right_first(data, philo))
		  return (1);
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
  pthread_mutex_unlock(philo->right_fork);
  pthread_mutex_unlock(philo->left_fork);
	return (0);
}

