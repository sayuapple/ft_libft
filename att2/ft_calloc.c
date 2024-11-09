/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:28:19 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/05 14:52:28 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	byte;
	void	*mem;

	if (!nmemb || !size)
	{
		return (malloc(0));
	}
	if (nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	byte = nmemb * size;
	mem = malloc(byte);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, byte);
	return (mem);
}
