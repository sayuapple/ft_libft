/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:04:00 by tkitago           #+#    #+#             */
/*   Updated: 2025/03/11 15:38:44 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_philo *philo, char *av[])
{
	philo->num_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->must_time_eat = ft_atoi(av[5]);
	else
		philo->must_time_eat = -1;
}

void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks,
		char *av[])
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating_flag = 0;
		philos[i].had_meal = 0;
		init_args(&philos[i], av);
		philos[i].start_time = get_current_time();
		philos[i].time_last_meal = get_current_time();
		philos[i].print_lock = &data->print_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].dead_flag = &data->dead_flag;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].num_philo - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_mutex(t_data *data, t_philo *philos)
{
	data->dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
}

int	init_thread(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	monitor_thread;
	int			i;

	if (pthread_create(&monitor_thread, NULL, &monitor, data->philos) != 0)
		destroy_all("error_create_thread", data, forks);
	i = 0;
	while (i < data->philos[0].num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]) != 0)
			destroy_all("error_create_thread", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor_thread, NULL) != 0)
		destroy_all("error_join_thread", data, forks);
	while (i < data->philos[0].num_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all("error_join_thread", data, forks);
		i++;
	}
	return (0);
}
