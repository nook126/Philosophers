/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:17:23 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/24 15:11:56 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime()
{
	struct timeval	tv;
	long			time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_stamp);
}
//^returns millisecounds since epoch

long	time_stamp(t_data *data)
{
	long	diff;

	diff = gettime() - data->start_time;
	return (diff);
}

void	log_event(t_data *data, size_t id, t_event event)
{
	pthread_mutex_lock(&data->print_mutex);
	if (event == FORK_TAKEN)
		printf("%ld %zu has taken a fork\n", time_stamp(data), id);
	else if (event == EATING)
		printf("%ld %zu is eating\n", time_stamp(data), id);
	else if (event == SLEEPING)
		printf("%ld %zu is sleeping\n", time_stamp(data), id);
	else if (event == THINKING)
		printf("%ld %zu is thinking\n", time_stamp(data), id);
	else if (event == DIED)
		printf("%ld %zu died\n", time_stamp(data), id);
	pthread_mutex_unlock(&data->print_mutex);
}
