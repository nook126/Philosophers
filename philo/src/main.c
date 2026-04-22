/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:24:17 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/22 17:15:05 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 6 || argc < 5)
	{
		printf("Usage: ./philo <#philos> <to die> <to eat> <to sleep> [<# of eats>]");
		return (1);
	}
	init_philos(&data, argc, argv);
	cleanup_data(&data);
	return (0);
}
