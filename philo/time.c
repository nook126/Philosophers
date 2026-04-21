/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:17:23 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/21 16:09:47 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	gettime()
{
	struct timeval blah;

	gettimeofday(&blah, NULL);

	printf("sec:%ld, msec:%ld\n", blah.tv_sec , blah.tv_usec);
	return (0);
}
