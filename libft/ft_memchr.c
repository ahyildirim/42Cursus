/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:47:17 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/15 20:47:40 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*xs;

	i = -1;
	xs = (char *)s;
	while (++i < n)
		if (*xs++ == (char)c)
			return ((char *)(xs - 1));
	return (0);
}
