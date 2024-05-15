/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:01:42 by ahyildir          #+#    #+#             */
/*   Updated: 2024/02/05 18:10:47 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*firstline(int fd, char *buffer)
{
	char	*buf;
	int		char_read;

	char_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!found_new_line(buffer) && char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = firstline(fd, buf[fd]);
	if (buf[fd] == NULL)
		return (NULL);
	line = get_new_line(buf[fd]);
	buf[fd] = get_new_buffer(buf[fd]);
	return (line);
}
