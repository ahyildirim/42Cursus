/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:39:49 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:39:49 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*c_src;
	char		*c_dst;

	i = -1;
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (!dst && !src)
		return (NULL);
	else if (dst == src)
		return (dst);
	else if (c_dst > c_src)
		while (len-- > 0)
			c_dst[len] = c_src[len];
	else
		while (++i < len)
			c_dst[i] = c_src[i];
	return (dst);
}
