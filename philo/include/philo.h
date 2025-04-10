/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:01 by tkitago           #+#    #+#             */
/*   Updated: 2025/03/11 15:39:00 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 250

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating_flag;
	int				had_meal;
	size_t			time_last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_philo;
	int				must_time_eat;
	int				*dead_flag;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	t_philo			*philos;
}					t_data;

void				destroy_all(char *str, t_data *data,
						pthread_mutex_t *forks);
void				init_mutex(t_data *data, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_philo *philos, t_data *data,
						pthread_mutex_t *forks, char *av[]);
void				init_args(t_philo *philo, char *av[]);
int					init_thread(t_data *data, pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
int					dead_loop(t_philo *philo);
int					ft_atoi(char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				print_status(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

#endif
