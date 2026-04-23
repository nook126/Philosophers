/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:30:56 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/23 16:46:46 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data *data)
{
	printf("data->philo_count:%zu\n",data->philo_count);
	printf("data->time_to_die:%zu\n", data->time_to_die);
	printf("data->time_to_eat:%zu\n", data->time_to_eat);
	printf("data->time_to_sleep:%zu\n", data->time_to_sleep);
	printf("data->must_eat_count:%zu\n",data->must_eat_count);
}

int	create_philos(t_data *data)
{
	if (!(data->philos = malloc(data->philo_count * sizeof(t_philosopher))))
		return (-1);
	return (0);
}

int	create_forks(t_data *data)
{
	size_t	i;

	if (!(data->forks = malloc(data->philo_count * sizeof(pthread_mutex_t))))
		return (-1);
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_philos(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = 0;
	create_philos(data);
	create_forks(data);
	// print_data(data);
	return (1);
}
