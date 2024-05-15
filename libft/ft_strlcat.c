/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktas <ktas@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:37:10 by ktas              #+#    #+#             */
/*   Updated: 2023/12/15 15:37:12 by ktas             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	ss;
	int		i;

	i = -1;
	ds = ft_strlen(dst);
	ss = ft_strlen(src);
	if (!dstsize || dstsize <= ds)
		return (dstsize + ss);
	while (src[++i] && i < dstsize - ds - 1)
		dst[ds + i] = src[i];
	dst[ds + i] = '\0';
	return (ds + ss);
}
