/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:57:06 by dprudnik          #+#    #+#             */
/*   Updated: 2026/04/29 15:35:01 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
#define PHILOS_H

#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_data t_data;

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
  size_t			    id;

  size_t			    eat_count;
  unsigned long		last_meal_timestamp;
  pthread_mutex_t meal_mutex;

  pthread_t			  thread;
  t_data				  *data;
  pthread_mutex_t	*left_fork;
  pthread_mutex_t	*right_fork;
}					        t_philosopher;

typedef struct		s_data
{
  size_t			    philo_count;
  size_t		    	time_to_die;
  size_t			    time_to_eat;
  size_t			    time_to_sleep;
  size_t			    must_eat_count;

  unsigned long 	start_time;

  pthread_mutex_t	print_mutex;
  pthread_mutex_t	death_mutex;
  size_t			    death_flag;

  pthread_t			  monitor_thread;
  pthread_mutex_t	*forks;
  t_philosopher		*philos;
}					        t_data;

// clean_up.c
int	cleanup_data(t_data *data);

//events.c
int check_death(t_data *data);
int	eat_event(t_data *data, t_philosopher *philo);
int	sleep_event(t_data *data, t_philosopher *philo);
int	think_event(t_data *data, t_philosopher *philo);

//forks.c
int	take_right_first(t_data *data, t_philosopher *philo);
int	take_left_first(t_data *data, t_philosopher *philo);
int	takeforks_event(t_data *data, t_philosopher *philo);
int	returnforks_event(t_data *data, t_philosopher *philo);

// init.c
void init_mutexes(t_data *data);
void init_philos(t_data *data);
int init_threads(t_data *data);
int init_data(t_data *data, int argc, char **argv);

//init_utils.c
int create_philos(t_data *data);
int create_forks(t_data *data);

// log.c
unsigned long get_time(void);
unsigned long time_stamp(t_data *data);
void log_event(t_data *data, size_t id, t_event event);

// main.c
void	debug_philo(t_philosopher *philo, int flag);//DEBUG ONLY!
void	*life_time(void *arg);
void	*monitor_thread(void *arg);

// utils.c
int	ft_atoi(const char *nptr);

#endif
