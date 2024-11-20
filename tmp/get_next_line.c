/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:26:48 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/20 18:28:30 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *accum_buf, char *buf)
{
	char	*tmp_buf;

	tmp_buf = ft_strjoin(accum_buf, buf);
	free(accum_buf);
	return (tmp_buf);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	free(buffer);
	return (next_line);
}

char	*ft_first_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *accum_buf)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			byte_read;

	if (!accum_buf)
		accum_buf = ft_calloc(1, 1);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		buffer[byte_read] = '\0';
		accum_buf = ft_free(accum_buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (accum_buf[0] == '\0')
	{
		free(accum_buf);
		return (NULL);
	}
	return (accum_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_first_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

// #include "stdio.h"
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	line = (char*)1;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// }
