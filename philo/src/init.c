/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:30:56 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:20:58 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_init(&data->philos[i++].meal_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->access_mutex, NULL);
	data->death_flag = 0;
}

void	init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal_timestamp = time_stamp(data);
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i % data->philo_count];
		if (data->philo_count == 1)
			data->philos[i].right_fork = NULL;//TODO:
		else
			data->philos[i].right_fork = &data->forks[(i + 1)
				% data->philo_count];
		i++;
	}
}

int	init_threads(t_data *data)
{
	size_t	i;

	if (pthread_create(&data->monitor_thread, NULL, &monitor_thread,
			data) != 0)
		return (-1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &life_time,
				&data->philos[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = 0;
	data->start_time = get_time();
	data->sim_stopped = 0;
	if (create_philos(data) != 0)
		return (-1);
	if (create_forks(data) != 0)
		return (-1);
	init_mutexes(data);
	init_philos(data);
	if (init_threads(data) != 0)
		return (-1);
	return (0);
}
