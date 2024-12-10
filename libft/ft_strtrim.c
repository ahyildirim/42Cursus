/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:53:06 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/15 20:53:08 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checker(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	x;

	x = 0;
	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (s1[i] && ft_checker(s1[i], set))
		i++;
	while (j > i && ft_checker(s1[j - 1], set))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[x] = s1[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}
