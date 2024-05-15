/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:41:34 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:41:35 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;
	char	*find;

	i = 0;
	str = (char *)haystack;
	find = (char *)needle;
	if (!find[0])
		return (str);
	while (i < len && str[i])
	{
		j = 0;
		k = i;
		while ((str[k] == find[j]) && str[k] && k < len)
		{
			k++;
			j++;
		}
		if (find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
