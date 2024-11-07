/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:19:45 by tkitago           #+#    #+#             */
/*   Updated: 2024/10/31 13:50:25 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	*free_memory(char **lst, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(lst[j]);
		j++;
	}
	return (free(lst), NULL);
}

static char	*extract_word(char const *s, char c, size_t *word_len)
{
	if (!ft_strchr(s, c))
		*word_len = ft_strlen(s);
	else
		*word_len = ft_strchr(s, c) - s;
	return (ft_substr(s, 0, *word_len));
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			lst[i] = extract_word(s, c, &word_len);
			if (!lst[i])
				return (free_memory(lst, i));
			i++;
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
