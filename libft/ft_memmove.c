/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktas <ktas@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:24 by ktas              #+#    #+#             */
/*   Updated: 2023/12/15 15:30:25 by ktas             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = -1;
	d = (char *)dest;
	s = (const char *)src;
	if (!s && !d)
		return (0);
	if (d < s)
		while (++i < len)
			d[i] = s[i];
	else if (d > s)
		while (len--)
			d[len] = s[len];
	return (dest);
}
