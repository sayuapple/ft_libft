/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:04:17 by tkitago           #+#    #+#             */
/*   Updated: 2025/03/11 15:39:38 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define PHILO_DIE 1
#define PHILO_ALIVE 0
#define PHILO_FULL 1
#define PHILO_HUNGER 0

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

static int	check_dead_util(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->time_last_meal >= time_to_die
		&& philo->eating_flag == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (PHILO_DIE);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (PHILO_ALIVE);
}

static int	check_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_philo)
	{
		if (check_dead_util(&philos[i], philos[i].time_to_die))
		{
			print_status("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead_flag = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (PHILO_DIE);
		}
		i++;
	}
	return (PHILO_ALIVE);
}

static int	check_all_full(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].must_time_eat == -1)
		return (PHILO_HUNGER);
	while (i < philos[0].num_philo)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].had_meal >= philos[i].must_time_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_philo)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead_flag = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (PHILO_FULL);
	}
	return (PHILO_HUNGER);
}

void	*monitor(void *args)
{
	t_philo	*philos;

	philos = (t_philo *)args;
	while (1)
	{
		if (check_dead(philos) == 1 || check_all_full(philos) == 1)
			break ;
	}
	return (args);
}
