/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:30:56 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/24 15:11:52 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_data *data)
{
	if (!(data->philos = malloc(data->philo_count * sizeof(t_philosopher))))
		return (-1);
	return (0);
}

int	create_forks(t_data *data)
{
	if (!(data->forks = malloc(data->philo_count * sizeof(pthread_mutex_t))))
		return (-1);
	return (0);
}

void	init_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
}

int	init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].left_fork = &data->forks[i %data->philo_count];
		if (data->philo_count == 1)
			data->philos[i].right_fork = NULL;
		else
			data->philos[i].right_fork = &data->forks[(i + 1) %data->philo_count];
		if (pthread_create(&data->philos[i].thread, NULL, &life_time, data) != 0)
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
	if (create_philos(data) != 0)
		return (-1);
	if (create_forks(data) != 0)
		return (-1);
	init_mutexes(data);
	if (init_philos(data) != 0)
		return (-1);
	return (0);
}
