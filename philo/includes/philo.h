/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:57:06 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/22 17:14:44 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philosopher
{
	size_t			id;

	size_t			eat_count;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	// t_data			*data;

}				t_philosopher;


typedef struct		s_data
{
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat_count;

	size_t			start_time;

	//pthread_mutex_t	print_mutex;//?
	//pthreead_mutex_t	death_mutex;//?

	pthread_mutex_t	*forks;
	t_philosopher	*philos;
}					t_data;


//init.c
int	init_philos(t_data *data, int argc, char **argv);

//utils.c
int	ft_atoi(const char *nptr);

//clean_up.c
void	cleanup_data(t_data *data);

# endif
