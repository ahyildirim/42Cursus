/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:48:40 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/15 20:48:41 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	i = -1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!s && !d)
		return (dest);
	if (d > s)
		while (len--)
			d[len] = s[len];
	else
		while (++i < len)
			d[i] = s[i];
	return (dest);
}
