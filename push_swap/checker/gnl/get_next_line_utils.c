/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:02 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:43:43 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ftt_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ftt_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ftt_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ftt_strdup(const char *s1)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ftt_strlen(s1) + 1));
	i = -1;
	if (dest == NULL)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}

char	*ftt_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	lens1;
	char	*dst;

	lens1 = ftt_strlen(s1);
	i = -1;
	dst = malloc(sizeof(char) * (lens1 + ftt_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[++i])
		dst[i] = (char )s1[i];
	i = -1;
	while (s2[++i])
	{
		dst[lens1] = s2[i];
		lens1++;
	}
	dst[lens1] = '\0';
	return (dst);
}

char	*ftt_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;

	i = 0;
	if (start > ftt_strlen(s))
		return (ftt_strdup(""));
	if (ftt_strlen(s) < len)
		len = ftt_strlen(s);
	ns = malloc(sizeof(char) * (len + 1));
	if (ns == NULL)
		return (NULL);
	while (s[start] && len > 0)
	{
		ns[i] = *(char *)(s + start);
		i++;
		start++;
		len--;
	}
	ns[i] = '\0';
	return (ns);
}
