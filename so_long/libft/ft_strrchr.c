/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:41:41 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:41:42 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	count;
	char	*cs;

	i = 0;
	count = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			cs = (char *) s + i;
			count = 1;
		}
		i++;
	}
	if (count > 0)
		return (cs);
	return (0);
}
