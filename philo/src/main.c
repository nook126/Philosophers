/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:24:17 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/29 14:20:38 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data *data)//DEBUG ONLY!
{
	printf("data->philo_count:%zu\n", data->philo_count);
	printf("data->time_to_die:%zu\n", data->time_to_die);
	printf("data->time_to_eat:%zu\n", data->time_to_eat);
	printf("data->time_to_sleep:%zu\n", data->time_to_sleep);
	printf("data->must_eat_count:%zu\n", data->must_eat_count);
}

 void	debug_philo(t_philosopher *philo, int flag)//DEBUG ONLY!
{
  printf("DEBUG!!!\n<\n");
  if (flag == 1)
    printf("In life_time_thread.\n");
	printf("Address: %p\n", philo);
  printf("id: %zu\n", philo->id);
  printf("eat_count: %zu\n", philo->eat_count);
  printf("last_meal_timestamp: %lu\n", philo->last_meal_timestamp);
  printf(">\n");
}

// TODO: handle returns of event functions
void	*life_time(void *arg)
{
  t_philosopher	*philo;
  size_t			i;

  philo = (t_philosopher *)arg;
  i = 0;
  while (i < philo->data->must_eat_count || philo->data->must_eat_count == 0)
  {
    if (eat_event(philo->data, philo))
      return (NULL);
    if (sleep_event(philo->data, philo))
      return (NULL);
    if (think_event(philo->data, philo))
      return (NULL);
    if (philo->data->must_eat_count == 0)
      i = 0;
    else
      i++;
  }
  return (NULL);
}

void	*monitor_thread(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	while (1)
	{
    i = 0;
    while (i < data->philo_count)
    {
      if (time_stamp(data) > (data->philos[i].last_meal_timestamp
            + (long)data->time_to_die))
      {
        pthread_mutex_lock(&data->death_mutex);
        data->death_flag = 1;
        log_event(data, data->philos[i].id, DIED);
        pthread_mutex_unlock(&data->death_mutex);
	      return (NULL);
      }
      i++;
    }
	}
	return (NULL);
}

//TODO:check returns from cleanup_data and other functions.
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 6 || argc < 5)
	{
		printf("Usage: ./philo <#philos> <die> <eat> <sleep> [<# of eats>]");
		return (1);
	}
	if (init_data(&data, argc, argv) == -1)
		return (1);
	if (cleanup_data(&data) == -1)
		return (1);
	return (0);
}
