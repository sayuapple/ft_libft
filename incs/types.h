/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:00:49 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 18:00:58 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_size
{
	int		width;
	int		height;
}			t_size;

typedef struct s_position
{
	double	x;
	double	y;
}			t_position;

#endif