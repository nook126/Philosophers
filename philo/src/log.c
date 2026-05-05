/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:17:23 by dprudnik          #+#    #+#             */
/*   Updated: 2026/05/05 15:28:24 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	tv;
	unsigned long	time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_stamp);
}
//^returns millisecounds since epoch

unsigned long	time_stamp(t_data *data)
{
	unsigned long	diff;

	diff = get_time() - data->start_time;
	return (diff);
}

void	log_event(t_data *data, size_t id, t_event event)
{
	pthread_mutex_lock(&data->print_mutex);
	if (event == FORK_TAKEN)
		printf("%lu %zu has taken a fork\n", time_stamp(data), id);
	else if (event == EATING)
		printf("%lu %zu is eating\n", time_stamp(data), id);
	else if (event == SLEEPING)
		printf("%lu %zu is sleeping\n", time_stamp(data), id);
	else if (event == THINKING)
		printf("%lu %zu is thinking\n", time_stamp(data), id);
	else if (event == DIED)
		printf("%lu %zu died\n", time_stamp(data), id);
	pthread_mutex_unlock(&data->print_mutex);
}
