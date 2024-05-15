/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ktas <ktas@student.42istanbul.com.tr>      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/12/15 15:35:48 by ktas              #+#    #+#             */
/*   Updated: 2023/12/15 15:35:50 by ktas             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst;
	unsigned const char	*sc;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < len)
		dst[i] = sc[i];
	return (dest);
}
