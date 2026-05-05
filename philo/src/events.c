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

int check_death(t_data *data)
{
  pthread_mutex_lock(&data->death_mutex);
  if (data->death_flag == 1)
  {
    pthread_mutex_unlock(&data->death_mutex);
    return (1);
  }
  pthread_mutex_unlock(&data->death_mutex);
  return (0);
}

int	eat_event(t_data *data, t_philosopher *philo)
{
  if (takeforks_event(data, philo))
    return (1);
  if (check_death(data))
    return (1);
  log_event(data, philo->id, EATING);
  pthread_mutex_lock(&philo->meal_mutex);
  philo->last_meal_timestamp = time_stamp(data);
  philo->eat_count++;
  pthread_mutex_unlock(&philo->meal_mutex);
  usleep(data->time_to_eat * 1000);
  returnforks_event(data, philo);
  return (0);
}

int	sleep_event(t_data *data, t_philosopher *philo)
{
  if (check_death(data))
    return (1);
  log_event(data, philo->id, SLEEPING);
  usleep(data->time_to_sleep * 1000);
  return (0);
}

//TODO: add fill-in time to maximize use of till death margin.
int	think_event(t_data *data, t_philosopher *philo)
{
  if (check_death(data))
    return (1);
  log_event(data, philo->id, THINKING);
  usleep(10 * 1000);//temporary!
  return (0);
}
