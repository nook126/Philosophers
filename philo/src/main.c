/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:24:17 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/24 15:44:20 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	print_data(t_data *data)//DEBUG ONLY!
{
	printf("data->philo_count:%zu\n",data->philo_count);
	printf("data->time_to_die:%zu\n", data->time_to_die);
	printf("data->time_to_eat:%zu\n", data->time_to_eat);
	printf("data->time_to_sleep:%zu\n", data->time_to_sleep);
	printf("data->must_eat_count:%zu\n", data->must_eat_count);
}

void	*life_time(void *arg)
{
	t_philosopher	*philo;
	size_t  i;

	philo = (t_philosopher *)arg;
	i = 0;
	while (i < philo->data->must_eat_count)
	{
		eat_event(philo->data, philo);
		i++;
	}
	return (NULL);
}

void	*monitor_thread(void *arg)
{
	t_data  *data;
	size_t  i;

	data = (t_data *)arg;
	i = 0;
	while (1)
	{
		while (i < data->philo_count)
		{
			if (time_stamp(data) > (long)(data->philos[i].last_meal_timestamp + data->time_to_die))
			{
				pthread_mutex_lock(&data->death_mutex);
				data->death_flag = 1;
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
	t_data  data;

	if (argc > 6 || argc < 5)
	{
		printf("Usage: ./philo <#philos> <to die> <to eat> <to sleep> [<# of eats>]");
		return (1);
	}
	init_data(&data, argc, argv);
	// print_data(&data);//DEBUG!
	cleanup_data(&data);
	return (0);
}

