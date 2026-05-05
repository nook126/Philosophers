/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:24:17 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:31:56 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
