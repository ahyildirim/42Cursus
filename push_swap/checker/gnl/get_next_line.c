/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:12:19 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:43:24 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str, char *src)
{
	int		val;
	char	*tmp;

	while (1)
	{
		val = read(fd, str, BUFFER_SIZE);
		if (val == -1)
			return (NULL);
		else if (val == 0)
			break ;
		str[val] = '\0';
		if (src == NULL)
			src = ftt_strdup("");
		tmp = src;
		src = ftt_strjoin(tmp, str);
		free(tmp);
		tmp = NULL;
		if (ftt_strchr(str, '\n'))
			break ;
	}
	return (src);
}

char	*ft_clean(char	*line)
{
	int		i;
	char	*dest;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	dest = ftt_substr(line, i + 1, ftt_strlen(line) - i);
	if (dest == NULL)
		return (NULL);
	if (dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*src;
	char		*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	line = ft_read(fd, str, src);
	free (str);
	if (line == NULL)
	{
		free(src);
		src = NULL;
		return (NULL);
	}
	src = ft_clean(line);
	return (line);
}
