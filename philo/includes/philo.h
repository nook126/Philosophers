/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:57:06 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/24 15:44:45 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum	e_event
{
				FORK_TAKEN,
				EATING,
				SLEEPING,
				THINKING,
				DIED
}				t_event;

typedef struct		s_philosopher
{
	size_t			id;

	size_t			eat_count;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philosopher;


typedef struct		s_data
{
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat_count;

	long			start_time;

	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;

	pthread_mutex_t	*forks;
	t_philosopher	*philos;
}					t_data;


//clean_up.c
int	cleanup_data(t_data *data);

//init.c
int	create_philos(t_data *data);
int	create_forks(t_data *data);
void	init_mutexes(t_data *data);
int	init_philos(t_data *data);
int	init_data(t_data *data, int argc, char **argv);

//log.c
long	get_time();
long	time_stamp(t_data *data);
void	log_event(t_data *data, size_t id, t_event event);

//main.c
void	*life_time(void *arg);

//utils.c
int	ft_atoi(const char *nptr);

# endif
