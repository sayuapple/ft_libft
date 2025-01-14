/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:26:21 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/29 14:43:35 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_2darraydel(void *array)
{
	char	**ptr;

	ptr = array;
	while (*ptr)
		free(*ptr++);
	free(array);
}
