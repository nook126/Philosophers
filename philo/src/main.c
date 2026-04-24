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
	t_data *data;

	data = (t_data *)arg;

	printf("%ld\n", data->start_time);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

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
